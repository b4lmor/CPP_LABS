//
// Created by afox on 10/3/23.
//

#include "RandomStrategy.h"

Choice RandomStrategy::make_choice(int prisoner_index, history_t history) {
    bool choice_bit = random() & 1;
    return choice_bit ? Cooperate : Defect;
}

std::string RandomStrategy::get_name() {
    return RANDOM_STRATEGY_NAME;
}
