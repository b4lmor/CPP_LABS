//
// Created by afox on 10/27/23.
//

#ifndef LAB3_PARSEDARGS_H
#define LAB3_PARSEDARGS_H

#include "../types/Mode.h"
#include <vector>
#include <string>

class ParsedArgs {
    std::vector<std::string> input_file_paths;
    std::string output_file_path;
    std::string config_file_path;
    Mode mode;
public:
    ParsedArgs(int argc, char *argv[]);
    std::vector<std::string> get_input_paths();
    std::string get_output_file_path();
    std::string get_config_file_path();
    Mode get_mode();
};


#endif //LAB3_PARSEDARGS_H
