//
// Created by afox on 10/13/23.
//

#ifndef LAB2_MIMICKERSTRATEGY_H
#define LAB2_MIMICKERSTRATEGY_H

#include "../AStrategy.h"

#define MIMICKER_STRATEGY_NAME "mimicker"

class MimickerStrategy : public AStrategy {
public:
    Choice make_choice(int prisoner_index, history_t history) override;
    std::string get_name() override;
};


#endif //LAB2_MIMICKERSTRATEGY_H
