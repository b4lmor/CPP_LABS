//
// Created by afox on 10/2/23.
//

#include "GameMatrix.h"

#include "../utils/file_utils/file_basic.h"
#include "../utils/regex_utils.h"

#include <fstream>
#include <string>

void GameMatrix::update_matrix(
        int arr[2][2][2][3], std::string input, std::set<int> * lines) {
    std::regex pattern(MATRIX_LINE_REGEX);
    std::smatch matches;

    if (std::regex_match(input, matches, pattern)) {
        int letter_indices[3];
        for (int i = 0; i < 3; i++) {
            if (matches[i + 1] == "C") {
                letter_indices[i] = 0;
            } else {
                letter_indices[i] = 1;
            }
        }

        int numbers[3];
        for (int i = 0; i < 3; i++) {
            numbers[i] = std::stoi(matches[i + 4]);
        }

        arr[letter_indices[0]][letter_indices[1]][letter_indices[2]][0]
                = numbers[0];
        arr[letter_indices[0]][letter_indices[1]][letter_indices[2]][1]
                = numbers[1];
        arr[letter_indices[0]][letter_indices[1]][letter_indices[2]][2]
                = numbers[2];

        int bijection = letter_indices[0]
                        + letter_indices[1] * 10
                        + letter_indices[2] * 100;

        if (lines->count(bijection) != 0) {
            throw std::runtime_error("matrix line duplicate");
        }

        lines->insert(bijection);

    } else {
        throw std::runtime_error("bad matrix line format");
    }
}

GameMatrix::GameMatrix() : GameMatrix(
        "/home/afox/Documents/Work/NSU/CPP_LABS/LAB2/resources/matrix-default.txt"
) {}

GameMatrix::GameMatrix(std::string file_path) {
    std::ifstream in_file;
    open_in_file(in_file, file_path);
    std::set<int> lines;

    while (!in_file.eof()) {
        std::string buf;
        getline(in_file, buf);
        update_matrix(matrix, buf, &lines);
    }

    if (lines.size() != 8) {
        throw std::runtime_error("inlaid number of lines");
    }

    in_file.close();
}

int GameMatrix::get_points_for_concrete(
        Choice c1, Choice c2, Choice c3, int prisoner_ind) {
    return matrix[c1][c2][c3][prisoner_ind];
}
