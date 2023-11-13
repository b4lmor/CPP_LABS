//
// Created by afox on 10/2/23.
//

#include "DetailedGame.h"

games_t DetailedGame::run_game() {
    return run_game_default(prisoner1, prisoner2, prisoner3, steps, matrix);
}

DetailedGame::DetailedGame(const Prisoner& p1, const Prisoner& p2, const Prisoner& p3,
                           const GameMatrix &mtrx, int s) {
    prisoner1 = p1;
    prisoner2 = p2;
    prisoner3 = p3;
    matrix = mtrx;
    steps = s;
}
