//
// Created by afox on 9/9/23.
//

#include "file_utils.h"
#include "my_exception.h"

void open_in_file(ifstream & in_file, string & in_path) {
    in_file.open(in_path);
    if (!in_file.is_open()) {
        throw my_exception("Can't open input file. Please, create it before use.");
    }
}

void open_out_file(ofstream & out_file, string & out_path) {
    out_file.open(out_path);
    if (!out_file.is_open()) {
        throw my_exception("Can't open output file. Please, create it before use.");
    }
}
