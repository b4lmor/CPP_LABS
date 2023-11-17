//
// Created by afox on 10/13/23.
//

#ifndef LAB2_COMBINEDSTRATEGY_H
#define LAB2_COMBINEDSTRATEGY_H

#include "../AStrategy.h"

#define COMBINED_STRATEGY_NAME "combined"

class CombinedStrategy : public AStrategy {
public:
    Choice make_choice(int prisoner_index, history_t history) override;
    std::string get_name() override;
    void apply_config(const std::string &config_path) override {}
};


#endif //LAB2_COMBINEDSTRATEGY_H
