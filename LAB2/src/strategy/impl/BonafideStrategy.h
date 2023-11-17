//
// Created by afox on 10/12/23.
//

#ifndef LAB2_BONAFIDESTRATEGY_H
#define LAB2_BONAFIDESTRATEGY_H

#include "../AStrategy.h"

#define BONAFIDE_STRATEGY_NAME "bonafide"

class BonafideStrategy : public AStrategy {
public:
    Choice make_choice(int prisoner_index, history_t history) override;
    std::string get_name() override;
    void apply_config(const std::string &config_path) override;
private:
    Choice start_choice = Cooperate;
};


#endif //LAB2_BONAFIDESTRATEGY_H
