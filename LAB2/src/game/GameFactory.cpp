//
// Created by afox on 10/4/23.
//

#include <stdexcept>
#include "GameFactory.h"
#include "impl/DetailedGame.h"
#include "impl/FastGame.h"
#include "impl/TournamentGame.h"

AGame * get_game_by_args(GameArgs args) {
    std::string mode_name = args.get_mode_name();
    std::string configs_dir_path(
            args.get_configs_dir_path()
            );

    switch (get_mode_by_string(mode_name)) {
        case GameMode::DETAILED:
            return new DetailedGame(
                    Prisoner(args.get_strategy_names()[0], 0, configs_dir_path),
                    Prisoner(args.get_strategy_names()[1], 1, configs_dir_path),
                    Prisoner(args.get_strategy_names()[2], 2, configs_dir_path),
                    GameMatrix(args.get_matrix_file_path())
            );
        case GameMode::FAST:
            return new FastGame(
                    Prisoner(args.get_strategy_names()[0], 0, configs_dir_path),
                    Prisoner(args.get_strategy_names()[1], 1, configs_dir_path),
                    Prisoner(args.get_strategy_names()[2], 2, configs_dir_path),
                    GameMatrix(args.get_matrix_file_path()),
                    args.get_steps()
            );
        case GameMode::TOURNAMENT:
            return new TournamentGame(
                    args.get_strategy_names(),
                    GameMatrix(args.get_matrix_file_path()),
                    args.get_steps(),
                    args.get_configs_dir_path()
            );
        default:
            throw std::runtime_error("undefined behavior");
    }

}
