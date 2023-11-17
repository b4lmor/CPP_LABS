//
// Created by afox on 9/30/23.
//

#ifndef LAB2_ASTRATEGY_H
#define LAB2_ASTRATEGY_H

#include "../utils/enum/Choice.h"
#include "../utils/my_types/MyTypes.h"

#include <list>
#include <tuple>
#include <string>

class AStrategy {
public:
    virtual Choice make_choice(int prisoner_index, history_t history) = 0;
    virtual std::string get_name() = 0;
    virtual void apply_config(const std::string &config_path) = 0;
    virtual ~AStrategy() = default;
};

#endif //LAB2_ASTRATEGY_H
