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
protected:
    games_t run_game_default(
            Prisoner prisoner1, Prisoner prisoner2, Prisoner prisoner3,
            int steps, GameMatrix matrix) {
        Choice c1, c2, c3;
        int income1, income2, income3;
        history_t history;
        history.prisoner_name1 = prisoner1.get_strategy_name();
        history.prisoner_name2 = prisoner2.get_strategy_name();
        history.prisoner_name3 = prisoner3.get_strategy_name();
        games_t games;
        games.prisoner_names.push_back(prisoner1.get_strategy_name());
        games.prisoner_names.push_back(prisoner2.get_strategy_name());
        games.prisoner_names.push_back(prisoner3.get_strategy_name());

        for (int round = 0; round < steps; round++) {
            c1 = prisoner1.make_choice(history);
            c2 = prisoner2.make_choice(history);
            c3 = prisoner3.make_choice(history);

            income1 = matrix.get_points_for_concrete(c1, c2, c3, 0);
            income2 = matrix.get_points_for_concrete(c1, c2, c3, 1);
            income3 = matrix.get_points_for_concrete(c1, c2, c3, 2);

            prisoner1.add_points(income1);
            prisoner2.add_points(income2);
            prisoner3.add_points(income3);

            history.add_move(c1, c2, c3,
                             prisoner1.get_points(),
                             prisoner2.get_points(),
                             prisoner3.get_points());
        }

        games.add_game_history(history);
        return games;
    }
public:
    virtual games_t run_game() = 0;
    virtual ~AGame()=default;
};

#endif //LAB2_AGAME_H
