//
// Created by afox on 10/2/23.
//

#include "file_basic.h"

void open_in_file(std::ifstream & in_file, std::string & in_path) {
    in_file.open(in_path);
    if (!in_file.is_open()) {
        throw std::ios::failure("Can't open input file. Please, create it before use.");
    }
}
