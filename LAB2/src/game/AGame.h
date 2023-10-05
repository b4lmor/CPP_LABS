//
// Created by afox on 9/30/23.
//

#ifndef LAB2_AGAME_H
#define LAB2_AGAME_H

#include <vector>
#include <map>
#include <tuple>

#include "../prisoner/Prisoner.h"
#include "../utils/enum/Choice.h"
#include "../matrix/GameMatrix.h"
#include "../utils/my_types/MyTypes.h"

typedef struct prisoners {
    prisoners(const Prisoner& p1, const Prisoner& p2, const Prisoner& p3) :
    prisoner1(p1), prisoner2(p2), prisoner3(p3){}

    Prisoner prisoner1;
    Prisoner prisoner2;
    Prisoner prisoner3;
} prisoners_t;

class AGame {
public:
    virtual void run_game() = 0;
};

#endif //LAB2_AGAME_H
