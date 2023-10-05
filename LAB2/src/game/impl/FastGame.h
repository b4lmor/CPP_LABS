//
// Created by afox on 10/5/23.
//

#ifndef LAB2_FASTGAME_H
#define LAB2_FASTGAME_H

#include "../AGame.h"

class FastGame : public AGame {
private:
    Prisoner prisoner1;
    Prisoner prisoner2;
    Prisoner prisoner3;
    GameMatrix matrix;
    history_t history;
    int steps;
public:
    FastGame(const Prisoner& p1, const Prisoner& p2, const Prisoner& p3,
                 const GameMatrix & mtrx, int s);
    void run_game() override;
};


#endif //LAB2_FASTGAME_H
