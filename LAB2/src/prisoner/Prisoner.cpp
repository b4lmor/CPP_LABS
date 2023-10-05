//
// Created by afox on 10/2/23.
//

#include "Prisoner.h"
#include "../strategy/StrategyFactory.h"

#include <utility>

Prisoner::Prisoner(const std::string & strategy_id, int p_ind) {
    prisoner_index = p_ind;
    strategy = get_strategy_by_id(strategy_id);
}

Choice Prisoner::make_choice(history_t history) {
    return this->strategy->make_choice(prisoner_index, std::move(history));
}

Prisoner::~Prisoner() {
    //delete[] strategy;
}

int Prisoner::get_points() {
    return points;
}

void Prisoner::add_points(int p) {
    points += p;
}

std::string Prisoner::get_strategy_name() {
    return strategy->get_name();
}

Prisoner::Prisoner(const std::string &strategy_id, int p_ind, std::string &cfg_path) {
    prisoner_index = p_ind;
    strategy = get_strategy_by_id(strategy_id);
    configs_file_path = cfg_path;
}

