//
// Created by afox on 9/9/23.
//

#ifndef LAB0B_FILE_UTILS_H
#define LAB0B_FILE_UTILS_H

#include <fstream>
#include <string>

using namespace std;

void open_in_file(ifstream & in_file, string & in_path);

void open_out_file(ofstream & out_file, string & out_path);

void write_to_file(ofstream & out_file, std::string word,
                   int amount, double percentage);

#endif //LAB0B_FILE_UTILS_H
