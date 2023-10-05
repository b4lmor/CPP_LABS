//
// Created by afox on 10/2/23.
//

#include "StrategyFactory.h"
#include "impl/AltruistStrategy.h"
#include "impl/BetrayerStrategy.h"
#include "impl/RandomStrategy.h"

AStrategy * get_strategy_by_id(const std::string & name) {
    if (name == ALTRUIST_STRATEGY_NAME) {
        return new AltruistStrategy();
    } else if (name == BETRAYER_STRATEGY_NAME) {
        return new BetrayerStrategy();
    } else if (name == RANDOM_STRATEGY_NAME) {
        return new RandomStrategy();
    } else {
        throw std::exception(); // TODO : exception
    }
}
