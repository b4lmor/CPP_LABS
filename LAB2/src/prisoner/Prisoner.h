//
// Created by afox on 9/30/23.
//

#ifndef LAB2_PRISONER_H
#define LAB2_PRISONER_H

#include "../utils/enum/Choice.h"
#include "../strategy/AStrategy.h"

#include <string>
#include <utility>
#include <memory>

class Prisoner {
    std::shared_ptr<AStrategy> strategy;
    int points = 0;
    int prisoner_index;
public:
    Prisoner(const std::string & strategy_id, int p_ind, const std::string & cfg_path);
    Prisoner() = default;
    ~Prisoner();
    Choice make_choice(history_t history);
    int get_points();
    void add_points(int p);
    std::string get_strategy_name();
};


#endif //LAB2_PRISONER_H
