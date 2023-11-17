//
// Created by afox on 10/2/23.
//

#include "Prisoner.h"
#include "../strategy/StrategyFactory.h"

#include <utility>

Choice Prisoner::make_choice(history_t history) {
    return strategy->make_choice(prisoner_index, std::move(history));
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

Prisoner::Prisoner(const std::string &strategy_id, int p_ind, const std::string &cfg_path) {
    prisoner_index = p_ind;
    strategy = std::shared_ptr<AStrategy>(get_strategy_by_id(strategy_id));
    if (!cfg_path.empty()) {
        strategy->apply_config(cfg_path);
    }
}

Prisoner::~Prisoner() = default;

