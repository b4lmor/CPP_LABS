//
// Created by afox on 10/13/23.
//

#include "MimickerStrategy.h"

#define MAX2(a, b) (a > b ? a : b)
#define MAX3(a, b, c) (MAX2( MAX2(a, b), c ))

Choice MimickerStrategy::make_choice(int prisoner_index, history_t history) {
    if (history.moves.empty()) {
        return Defect;
    }

    move_t prev_move = history.moves[history.moves.size() - 1];
    int max_points = MAX3(prev_move.points1,
                          prev_move.points2,
                          prev_move.points3);

    if (max_points == prev_move.points1) { return prev_move.choice1; }
    if (max_points == prev_move.points2) { return prev_move.choice2; }
    if (max_points == prev_move.points3) { return prev_move.choice3; }

    return Cooperate;
}

std::string MimickerStrategy::get_name() {
    return MIMICKER_STRATEGY_NAME;
}
