//
// Created by afox on 10/2/23.
//

#ifndef LAB2_BETRAYERSTRATEGY_H
#define LAB2_BETRAYERSTRATEGY_H

#define BETRAYER_STRATEGY_NAME "betrayer"

#include "../AStrategy.h"

class BetrayerStrategy : public AStrategy {
public:
    Choice make_choice(int prisoner_index, history_t history) override;
    std::string get_name() override;
};


#endif //LAB2_BETRAYERSTRATEGY_H
