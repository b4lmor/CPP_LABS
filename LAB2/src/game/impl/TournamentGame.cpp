//
// Created by afox on 10/5/23.
//

#include "TournamentGame.h"
#include "../../utils/combinations_utils.h"

games_t TournamentGame::run_game() {
    history_t history;
    games_t games;
    Choice c1, c2, c3;
    int income1, income2, income3;
    Prisoner prisoner1, prisoner2, prisoner3;
    int * points = new int[prisoner_names.size()];
    std::fill(points, points + prisoner_names.size(), 0);
    std::vector<std::vector<int>> triples =
            get_3combinations_of_interval((int) prisoner_names.size());

    for (auto triple : triples) {

        history = history_t();

        prisoner1 = Prisoner(prisoner_names[triple[0]], 0, configs_dir_path);
        prisoner2 = Prisoner(prisoner_names[triple[1]], 1, configs_dir_path);
        prisoner3 = Prisoner(prisoner_names[triple[2]], 2, configs_dir_path);

        history.prisoner_name1 = prisoner1.get_strategy_name();
        history.prisoner_name2 = prisoner2.get_strategy_name();
        history.prisoner_name3 = prisoner3.get_strategy_name();

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
                                 prisoner3.get_points()
                                 );
        }

        games.add_game_history(history);
        points[triple[0]] += prisoner1.get_points();
        points[triple[1]] += prisoner2.get_points();
        points[triple[2]] += prisoner3.get_points();
    }
    games.points = points;
    games.prisoner_names = prisoner_names;
    return games;
}

TournamentGame::TournamentGame(const std::vector<std::string>& p_names,
                               const GameMatrix & mtrx, int s, const std::string & cfg_path) {
    prisoner_names = p_names;
    matrix = mtrx;
    steps = s;
    configs_dir_path = cfg_path;
}
