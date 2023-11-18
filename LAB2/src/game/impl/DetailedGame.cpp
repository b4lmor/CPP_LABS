//
// Created by afox on 10/2/23.
//

#include <iostream>
#include "DetailedGame.h"
#include "../../renderer/GameRenderer.h"

games_t DetailedGame::run_game() {
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

    std::string input;
    int step = 0;
    while (input != "quit") {
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

        GameRenderer::render_round(
            step, history.moves[step],
            income1, income2, income3,
            prisoner1.get_strategy_name(),
            prisoner2.get_strategy_name(),
            prisoner3.get_strategy_name()
        );

        std::getline(std::cin, input);
        step++;
    }

    games.add_game_history(history);
    return games;
}

DetailedGame::DetailedGame(const Prisoner &p1, const Prisoner &p2, const Prisoner &p3,
                           const GameMatrix &mtrx) {
    prisoner1 = p1;
    prisoner2 = p2;
    prisoner3 = p3;
    matrix = mtrx;
}
