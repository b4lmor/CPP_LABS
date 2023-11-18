//
// Created by afox on 10/2/23.
//

#include <stdexcept>
#include "StrategyFactory.h"
#include "impl/AltruistStrategy.h"
#include "impl/BetrayerStrategy.h"
#include "impl/RandomStrategy.h"
#include "impl/BonafideStrategy.h"
#include "impl/MimickerStrategy.h"
#include "impl/CombinedStrategy.h"

AStrategy * get_strategy_by_id(const std::string & name) {
    if (name == ALTRUIST_STRATEGY_NAME) {
        return new AltruistStrategy();
    } else if (name == BETRAYER_STRATEGY_NAME) {
        return new BetrayerStrategy();
    } else if (name == RANDOM_STRATEGY_NAME) {
        return new RandomStrategy();
    } else if (name == BONAFIDE_STRATEGY_NAME) {
        return new BonafideStrategy();
    } else if (name == MIMICKER_STRATEGY_NAME) {
        return new MimickerStrategy();
    } else if (name == COMBINED_STRATEGY_NAME) {
        return new CombinedStrategy();
    } else {
        throw std::runtime_error("bad strategy name");
    }
}
