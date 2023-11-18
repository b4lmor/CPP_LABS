//
// Created by afox on 10/2/23.
//

#ifndef LAB2_DETAILEDGAME_H
#define LAB2_DETAILEDGAME_H

#include "../AGame.h"

class DetailedGame : public AGame {
private:
    Prisoner prisoner1;
    Prisoner prisoner2;
    Prisoner prisoner3;
    GameMatrix matrix;
public:
    DetailedGame(const Prisoner& p1, const Prisoner& p2, const Prisoner& p3,
                 const GameMatrix & mtrx);
    games_t run_game() override;
};

#endif //LAB2_DETAILEDGAME_H
