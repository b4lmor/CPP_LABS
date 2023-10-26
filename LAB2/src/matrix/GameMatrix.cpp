//
// Created by afox on 10/2/23.
//

#include "GameMatrix.h"

#include "../utils/file_utils/file_basic.h"
#include "../utils/regex_utils.h"

#include <fstream>
#include <string>

static void parse_line(int * p1, int * p2, int * p3,
                       Choice * c1, Choice * c2, Choice * c3,
                       std::string & line) {
    std::string num;
    line += ' ';
    int cnt = 0;
    for (char ch : line) {
        if (!isalnum(ch) && num.empty()) {
            continue;
        }

        if (cnt < 3) {
            switch (cnt) {
                case 0: *c1 = get_choice_by_char(ch); break;
                case 1: *c2 = get_choice_by_char(ch); break;
                case 2: *c3 = get_choice_by_char(ch); break;
            }
        } else {
            if (isdigit(ch)) {
                num.push_back(ch);
                continue;
            }
            switch (cnt) {
                case 3: *p1 = stoi(num); break;
                case 4: *p2 = stoi(num); break;
                case 5: *p3 = stoi(num); break;
            }
            num = "";
        }
        cnt++;
    }
}

GameMatrix::GameMatrix() : GameMatrix("/home/afox/Documents/Work/NSU/CPP_LABS/LAB2/resources/matrix-default.txt") {}

GameMatrix::GameMatrix(std::string file_path) {
    std::ifstream in_file;
    open_in_file(in_file, file_path);
    std::string buf;
    while (!in_file.eof()) {
        getline(in_file, buf);
        if (!compare_with_pattern(buf,
                                  MATRIX_LINE_REGEX)) {
            throw std::exception();
        }
        Choice c1, c2, c3;
        int p1, p2, p3;
        parse_line(&p1, &p2, &p3, &c1, &c2, &c3, buf);
        matrix[choices_t(c1, c2, c3)] = points_t(p1, p2, p3);
    }
}

points_t GameMatrix::get_points(Choice c1, Choice c2, Choice c3) {
    return matrix[choices_t(c1, c2, c3)];
}

int GameMatrix::get_points_for_first(Choice c1, Choice c2, Choice c3) {
    return std::get<0>(get_points(c1, c2, c3));
}

int GameMatrix::get_points_for_second(Choice c1, Choice c2, Choice c3) {
    return std::get<1>(get_points(c1, c2, c3));
}

int GameMatrix::get_points_for_third(Choice c1, Choice c2, Choice c3) {
    return std::get<2>(get_points(c1, c2, c3));
}

int GameMatrix::get_points_for_concrete(Choice c1, Choice c2, Choice c3, int prisoner_ind) {
    switch (prisoner_ind) {
        case 0:
            return get_points_for_first(c1, c2, c3);
        case 1:
            return get_points_for_second(c1, c2, c3);
        case 2:
            return get_points_for_third(c1, c2, c3);
        default:
            throw std::exception();
    }
}
