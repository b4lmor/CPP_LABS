//
// Created by afox on 10/2/23.
//

#include "BetrayerStrategy.h"

Choice BetrayerStrategy::make_choice(int prisoner_index, history_t history) {
    return Defect;
}

std::string BetrayerStrategy::get_name() {
    return BETRAYER_STRATEGY_NAME;
}
