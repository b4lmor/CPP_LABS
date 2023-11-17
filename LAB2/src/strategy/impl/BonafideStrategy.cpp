//
// Created by afox on 10/12/23.
//

#include "BonafideStrategy.h"

#include <regex>
#include <fstream>

#define COMMENT_SYMBOL '#'

#define CONFIG_FILE_NAME "bonafide.txt"
#define START_CHOICE_CONFIG_PARAMETER_PATTERN std::regex("start_choice:(defect|cooperate)")

static Choice get_own_choice(int index, move_t move) {
    switch (index) {
        case 1: return move.choice1;
        case 2: return move.choice2;
        case 3: return move.choice3;
        default: throw std::exception();
    }
}

Choice BonafideStrategy::make_choice(int prisoner_index, history_t history) {
    if (history.moves.empty()) {
        return start_choice;
    }

    move_t prev_move = history.moves[history.moves.size() - 1];
    int defect_counter =
            prev_move.choice1 == Defect ? 1 : 0
            + prev_move.choice2 == Defect ? 1 : 0
            + prev_move.choice3 == Defect ? 1 : 0
            - get_own_choice(prisoner_index, prev_move) == Defect ? 1 : 0;

    return defect_counter == 0 ? Cooperate : Defect;
}

std::string BonafideStrategy::get_name() {
    return BONAFIDE_STRATEGY_NAME;
}

void BonafideStrategy::apply_config(const std::string &config_path) {
    std::stringstream ss;
    ss << config_path
    << (config_path.substr(config_path.size() - 1)
        == std::string("/")
            ? ""
            : "/"
        )
    << CONFIG_FILE_NAME;

    std::string full_config_path = ss.str();

    std::ifstream file(full_config_path);

    if (!file.is_open()) {
        throw std::exception();
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line[0] == COMMENT_SYMBOL) {
            continue;
        }
        if (std::regex_match(line, START_CHOICE_CONFIG_PARAMETER_PATTERN)) {
            start_choice
            = line.substr(std::string("start_choice:").size())
                    == std::string("defect")
                      ? Defect
                      : Cooperate;
        }
    }

    file.close();
}
