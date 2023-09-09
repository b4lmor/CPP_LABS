//
// Created by afox on 9/9/23.
//

#ifndef LAB0B_UTILS_H
#define LAB0B_UTILS_H

#include <string>
#include <list>
#include <fstream>

using namespace std;

double get_percentage(int aggregate, int part);

void split(string const & line, list<string> & out);

void parse_args(string & in, string & out, int argc, char * argv[]);

#endif //LAB0B_UTILS_H
