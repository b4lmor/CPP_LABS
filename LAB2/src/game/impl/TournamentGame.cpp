//
// Created by afox on 10/5/23.
//

#include "TournamentGame.h"
#include "../../utils/combinations_utils.h"
#include "DetailedGame.h"

games_t TournamentGame::run_game() {
    games_t games;
    Prisoner prisoner1, prisoner2, prisoner3;
    std::shared_ptr<int> shared_points(new int[prisoner_names.size()]);
    int * points = shared_points.get();
    std::fill(points, points + prisoner_names.size(), 0);
    std::vector<std::vector<int>> triples =
            get_3combinations_of_interval((int) prisoner_names.size());

    for (auto triple : triples) {

        prisoner1 = Prisoner(prisoner_names[triple[0]], 0, configs_dir_path);
        prisoner2 = Prisoner(prisoner_names[triple[1]], 1, configs_dir_path);
        prisoner3 = Prisoner(prisoner_names[triple[2]], 2, configs_dir_path);

        DetailedGame game(prisoner1, prisoner2, prisoner3,
                          matrix, steps);
        games_t sub_games = game.run_game();

        history_t history = sub_games.games_history[0];

        games.add_game_history(history);
        points[triple[0]] += history.moves[steps - 1].points1;
        points[triple[1]] += history.moves[steps - 1].points2;
        points[triple[2]] += history.moves[steps - 1].points3;
    }

    games.points = shared_points;
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
