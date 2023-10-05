//
// Created by afox on 10/2/23.
//

#include "AltruistStrategy.h"

Choice AltruistStrategy::make_choice(int prisoner_index, history_t history) {
    return Cooperate;
}

std::string AltruistStrategy::get_name() {
    return ALTRUIST_STRATEGY_NAME;
}
