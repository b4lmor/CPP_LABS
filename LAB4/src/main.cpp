#include <iostream>

#include <iostream>
#include <fstream>
#include <sstream>
#include <tuple>
#include <format>

#define CSV_FILE_PATH R"(C:\pets\c++\CPP_LABS2\LAB4\resources\test.csv)"
#define SEPARATOR_DEFAULT ','
#define ESCAPE_CHARACTER_DEFAULT '"'


template<typename Ch, typename Tr, typename... Args, std::size_t... Is>
void print_tuple(std::basic_ostream<Ch, Tr>& os, const std::tuple<Args...>& t, std::index_sequence<Is...>) {
    ((os << (Is == 0 ? "" : ", ") << std::get<Is>(t)), ...);
}

template<typename Ch, typename Tr, typename... Args>
std::basic_ostream<Ch, Tr>& operator<<(std::basic_ostream<Ch, Tr>& os, const std::tuple<Args...>& t) {
    os << "(";
    print_tuple(os, t, std::index_sequence_for<Args...>{});
    os << ")";
    return os;
}

template<typename... Args>
class CSVParser {
public:
    CSVParser(std::ifstream& file, const int skip_lines, const char separator, const char escape) : file(file),
        skip_lines(skip_lines), separator(separator), escape(escape) {
    }

    CSVParser(std::ifstream& file, const int skip_lines, const char separator) : file(file), skip_lines(skip_lines),
        separator(separator) {
    }

    CSVParser(std::ifstream& file, const int skip_lines) : file(file), skip_lines(skip_lines) {
    }

    class Iterator {
    public:
        Iterator(std::ifstream& file, const int skip_lines, const char separator,
                 const char escape) : file(file), separator(separator), escape(escape) {
            for (int i = 0; i < skip_lines; ++i) {
                std::string line;
                std::getline(file, line);
            }
        }

        bool operator!=(const Iterator& other) const {
            return !file.eof();
        }

        std::tuple<Args...> operator*() {
            std::string line;
            std::getline(file, line);
            std::stringstream ss(line);
            row++;
            column = 0;
            return parse_line<Args...>(ss);
        }

        void operator++() const {
        }

    private:
        std::ifstream& file;
        char separator;
        char escape;
        std::tuple<Args...> current_row;
        int row = 0;
        int column = 0;

        template<typename T>
        std::tuple<T> parse_element(std::stringstream& ss) {
            column++;
            T last = parse_field<T>(ss);
            return std::make_tuple(last);
        }

        template<typename T, typename... Rest>
        std::tuple<T, Rest...> parse_line(std::stringstream& ss) {
            column++;
            T first = parse_field<T>(ss);

            if constexpr (sizeof...(Rest) == 0) {
                return std::tuple<T>(first);
            } else if constexpr (sizeof...(Rest) == 1) {
                auto rest = parse_element<Rest...>(ss);
                return std::tuple_cat(std::make_tuple(first), rest);
            } else {
                auto rest = parse_line<Rest...>(ss);
                return std::tuple_cat(std::make_tuple(first), rest);
            }
        }

        template<typename T>
        T parse_field(std::stringstream& ss) {
            T field;
            std::string tmp;
            std::string line;

        marker:
            std::getline(ss, tmp, separator);

            if (tmp.ends_with(escape)) {
                tmp[tmp.size() - 1] = separator;
                line += tmp;
                goto marker;
            }

            line += tmp;
            std::stringstream ss_parsed(line);
            ss_parsed >> field;

            if (!ss_parsed.eof()) {
                throw std::runtime_error(
                    std::format("Invalid data (row: {}, column: {})",
                                row, column)
                );
            }

            return field;
        }
    };

    Iterator begin() {
        return Iterator(file, skip_lines, separator, escape);
    }

    Iterator end() {
        return Iterator(file, 0, separator, escape);
    }

private:
    std::ifstream& file;
    int skip_lines;
    char separator = SEPARATOR_DEFAULT;
    char escape = ESCAPE_CHARACTER_DEFAULT;
};


int main() {
    const std::tuple<int, double, std::string, int, int, int> tup(42, 3.14, "hello", 1, 2, 3);
    std::cout << "Tuple printer:" << std::endl;
    std::cout << tup << std::endl;
    std::cout << "=================" << std::endl;

    std::ifstream file(CSV_FILE_PATH);
    if (!file.is_open()) {
        throw std::runtime_error("Can't open the csv file.");
    }

    CSVParser<int, std::string, double> parser(file, 1, ',');

    std::cout << "Parsed tuples:" << std::endl;
    for (auto csv_tuple: parser) {
        std::cout << csv_tuple << std::endl;
    }

    return 0;
}
