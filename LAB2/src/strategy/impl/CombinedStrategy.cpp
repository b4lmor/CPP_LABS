//
// Created by afox on 10/13/23.
//

#include "CombinedStrategy.h"
#include "../StrategyFactory.h"
#include "AltruistStrategy.h"
#include "BetrayerStrategy.h"
#include "RandomStrategy.h"
#include "BonafideStrategy.h"
#include "MimickerStrategy.h"
#include <memory>

Choice CombinedStrategy::make_choice(int prisoner_index, history_t history) {

    int strategy_id = (int) history.moves.size() % 5;
    std::unique_ptr<AStrategy> strategy;
    switch (strategy_id) {
        case 0: strategy = std::unique_ptr<AStrategy>(get_strategy_by_id(ALTRUIST_STRATEGY_NAME)); break;
        case 1: strategy = std::unique_ptr<AStrategy>(get_strategy_by_id(BETRAYER_STRATEGY_NAME)); break;
        case 2: strategy = std::unique_ptr<AStrategy>(get_strategy_by_id(RANDOM_STRATEGY_NAME));   break;
        case 3: strategy = std::unique_ptr<AStrategy>(get_strategy_by_id(BONAFIDE_STRATEGY_NAME)); break;
        case 4: strategy = std::unique_ptr<AStrategy>(get_strategy_by_id(MIMICKER_STRATEGY_NAME)); break;
        default: return Defect;
    }
    return strategy->make_choice(prisoner_index, history);
}

std::string CombinedStrategy::get_name() {
    return COMBINED_STRATEGY_NAME;
}
