//
// Created by afox on 10/3/23.
//

#ifndef LAB2_RANDOMSTRATEGY_H
#define LAB2_RANDOMSTRATEGY_H

#include "../AStrategy.h"

#define RANDOM_STRATEGY_NAME "randomer"

class RandomStrategy : public AStrategy{
public:
    Choice make_choice(int prisoner_index, history_t history) override;
    std::string get_name() override;
    void apply_config(const std::string &config_path) override {}
};


#endif //LAB2_RANDOMSTRATEGY_H
