//
// Created by afox on 9/30/23.
//

#ifndef LAB2_PRISONER_H
#define LAB2_PRISONER_H

#include "../utils/enum/Choice.h"
#include "../strategy/AStrategy.h"

#include <string>
#include <utility>

class Prisoner {
    AStrategy * strategy;
    std::string configs_file_path;
    int points = 0;
    int prisoner_index;
public:
    Prisoner(const std::string & strategy_id, int p_ind);
    Prisoner(const std::string & strategy_id, int p_ind, std::string & cfg_path);
    Choice make_choice(history_t history);
    int get_points();
    void add_points(int p);
    std::string get_strategy_name();
    ~Prisoner();
    Prisoner() = default;
};


#endif //LAB2_PRISONER_H
