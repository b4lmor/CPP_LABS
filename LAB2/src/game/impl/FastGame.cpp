//
// Created by afox on 10/5/23.
//

#include "FastGame.h"
#include "DetailedGame.h"

games_t FastGame::run_game() {
    DetailedGame game(prisoner1, prisoner2, prisoner3,
                      matrix, steps);
    games_t games = game.run_game();

    return games;
}

FastGame::FastGame(const Prisoner& p1, const Prisoner& p2, const Prisoner& p3,
                           const GameMatrix &mtrx, int s) {
    prisoner1 = p1;
    prisoner2 = p2;
    prisoner3 = p3;
    matrix = mtrx;
    steps = s;
}

