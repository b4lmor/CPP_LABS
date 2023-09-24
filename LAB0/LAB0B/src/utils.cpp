//
// Created by afox on 9/9/23.
//

#include "utils.h"
#include "my_exception.h"

double get_percentage(int aggregate, int part) {
    return (100.0 / aggregate) * part;
}

void split(string const & line, list<string> & out) {
    string to_push;
    for (char c : line) {
        if (isalnum(c)) {
            to_push.push_back(c);
        } else {
            if (!to_push.empty()) {
                out.push_back(to_push);
            }
            to_push.clear();
        }
    }
    if (!to_push.empty()) { out.push_back(to_push); }
}

static bool endsWithSubstring(
        const std::string & str,
        const std::string & subStr) {

    size_t strLen = str.length();
    size_t subStrLen = subStr.length();

    return  strLen >= subStrLen &&
            str.compare(strLen - subStrLen, subStrLen, subStr) == 0;
}

void parse_args(string & in, string & out, int argc, char * argv[]) {
    if (argc != 3) {
        throw my_exception("Invalid number of parameters. Try: `word_count.exe in.txt out.csv`.");
    } else if (!endsWithSubstring(argv[1], ".txt")) {
        throw my_exception("Input file should be in .txt format.");
    } else if (!endsWithSubstring(argv[2], ".csv")) {
        throw my_exception("Output file should be in .csv format.");
    }
    in = argv[1];
    out = argv[2];
}
