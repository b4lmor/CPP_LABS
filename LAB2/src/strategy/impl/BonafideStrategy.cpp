//
// Created by afox on 10/12/23.
//

#include "BonafideStrategy.h"

Choice BonafideStrategy::make_choice(int prisoner_index, history_t history) {
    if (history.moves.size() < 2) {
        return Cooperate;
    }

    move_t prev_move = history.moves[history.moves.size() - 1];
    int defect_counter = 0;

    defect_counter += isDefectFromOther(prisoner_index, 0, prev_move.choice1);
    defect_counter += isDefectFromOther(prisoner_index, 1, prev_move.choice2);
    defect_counter += isDefectFromOther(prisoner_index, 2, prev_move.choice3);

    return defect_counter == 0 ? Cooperate : Defect;
}

std::string BonafideStrategy::get_name() {
    return BONAFIDE_STRATEGY_NAME;
}

int BonafideStrategy::isDefectFromOther(int prisoner_index,
                                        int choicer_index,
                                        Choice choice) {
    return prisoner_index == choicer_index ? 0 : (
                choice == Defect ? 1 : 0
            );
}
