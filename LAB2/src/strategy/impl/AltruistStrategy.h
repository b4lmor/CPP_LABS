//
// Created by afox on 10/2/23.
//

#ifndef LAB2_ALTRUISTSTRATEGY_H
#define LAB2_ALTRUISTSTRATEGY_H

#define ALTRUIST_STRATEGY_NAME "altruist"

#include "../AStrategy.h"

class AltruistStrategy : public AStrategy {
public:
    Choice make_choice(int prisoner_index, history_t history) override;
    std::string get_name() override;
};


#endif //LAB2_ALTRUISTSTRATEGY_H
