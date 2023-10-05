//
// Created by afox on 9/29/23.
//

#ifndef LAB2_GAMEARGS_H
#define LAB2_GAMEARGS_H

#include <vector>
#include <string>

#include "../utils/enum/GameMode.h"

class GameArgs {
    std::vector<std::string> strategy_names;
    std::string mode_name;
    int steps;
    std::string configs_dir_path;
    std::string matrix_file_path;
public:
    GameArgs(int argc, char * argv[]);
    std::vector<std::string> get_strategy_names();
    int get_steps();
    std::string get_mode_name();
    std::string get_configs_dir_path();
    std::string get_matrix_file_path();
};

#endif //LAB2_GAMEARGS_H
