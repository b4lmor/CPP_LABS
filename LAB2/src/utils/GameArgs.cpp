//
// Created by afox on 10/4/23.
//

#include "GameArgs.h"
#include "regex_utils.h"

std::vector<std::string> GameArgs::get_strategy_names() {
    return strategy_names;
}

int GameArgs::get_steps() {
    return steps;
}

std::string GameArgs::get_mode_name() {
    return mode_name;
}

std::string GameArgs::get_configs_dir_path() {
    return configs_dir_path;
}

std::string GameArgs::get_matrix_file_path() {
    return matrix_file_path;
}

GameArgs::GameArgs(int argc, char * argv[]) {
    for (int i = 1; i < argc; i++) {
        std::string raw_arg(argv[i]);
        if (!compare_with_pattern(argv[i],
                                  R"(--.+)")) {
            strategy_names.emplace_back(argv[i]);
        } else if (compare_with_pattern(
                argv[i],
                R"(--mode=.*)")) {
            mode_name = replace_pattern(raw_arg,
                                        R"(--mode=)",
                                        "");
        } else if (compare_with_pattern(
                argv[i],
                R"(--steps=.*)")) {
            std::string steps_str = replace_pattern(raw_arg,
                                                   R"(--steps=)",
                                                   "");
            steps = stoi(steps_str);
        } else if (compare_with_pattern(
                argv[i],
                R"(--configs=.*)")) {
            configs_dir_path = replace_pattern(raw_arg,
                                               R"(--configs=)",
                                               "");
        } else if (compare_with_pattern(
                argv[i],
                R"(--matrix=.*)")) {
            matrix_file_path = replace_pattern(raw_arg,
                                               R"(--matrix=)",
                                               "");
        } else {
            throw std::exception();
        }
    }

    if (matrix_file_path.empty()) {
        matrix_file_path = "/home/afox/Documents/Work/NSU/CPP_LABS/LAB2/resources/matrix-default.txt";
    }
    if (steps <= 0) {
        steps = 1;
    }
    if (mode_name.empty()) {
        mode_name = "detailed";
    }
}

