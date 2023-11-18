//
// Created by afox on 10/13/23.
//

#include "GameRenderer.h"

#include <iostream>
#include <algorithm>

void GameRenderer::render_round(int step, const move_t& move,
                                int income1, int income2, int income3,
                                const std::string& name1, const std::string& name2, const std::string& name3) {
    std::cout << "round #"<< step + 1 << std::endl;

    std::cout << name1 << " | " << choice_to_string(move.choice1)
    << " | " << move.points1 << " (+" << income1 << ")" << std::endl;
    std::cout << name2 << " | " << choice_to_string(move.choice2)
    << " | " << move.points2 << " (+" << income2 << ")" << std::endl;
    std::cout << name3 << " | " << choice_to_string(move.choice3)
    << " | " << move.points3 << " (+" << income3 << ")" << std::endl;
}

void GameRenderer::render_results(const move_t& last_move, int steps,
                                  const std::string& name1,
                                  const std::string& name2,
                                  const std::string& name3) {
    std::cout << "rounds: " << steps << std::endl;
    std::cout << name1 << " | " << last_move.points1 << std::endl;
    std::cout << name2 << " | " << last_move.points2 << std::endl;
    std::cout << name3 << " | " << last_move.points3 << '\n' << std::endl;

}

void GameRenderer::render_fast_game(games_t games) {
    history_t game_history = games.games_history[0];
    render_results(
            game_history.moves[game_history.moves.size() - 1],
            (int) game_history.moves.size(),
            game_history.prisoner_name1,
            game_history.prisoner_name2,
            game_history.prisoner_name3
            );
}

void GameRenderer::render_game(GameArgs args, const games_t& games) {
    std::string mode_name = args.get_mode_name();
    GameMode mode = get_mode_by_string(mode_name);
    switch (mode) {
        case GameMode::DETAILED:
            render_detailed_game(games);
            break;
        case GameMode::FAST:
            render_fast_game(games);
            break;
        case GameMode::TOURNAMENT:
            render_tournament_game(games);
            break;
    }
}

void GameRenderer::render_detailed_game(games_t games) {
    history_t game_history = games.games_history[0];
    render_results(
            game_history.moves[game_history.moves.size() - 1],
            (int) game_history.moves.size(),
            game_history.prisoner_name1,
            game_history.prisoner_name2,
            game_history.prisoner_name3
    );
}

static std::vector<int> find_max_indices(const int* arr, int size) {

    std::vector<int> maxIndices;
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] == max) {
            maxIndices.push_back(i);
        }
    }

    return maxIndices;
}

void GameRenderer::render_tournament_game(games_t games) {
    for (auto game_history : games.games_history) {
        render_results(
                game_history.moves[game_history.moves.size() - 1],
                (int) game_history.moves.size(),
                game_history.prisoner_name1,
                game_history.prisoner_name2,
                game_history.prisoner_name3
        );
    }

    auto winners = find_max_indices(
            games.points.get(), games.prisoner_names.size());

    std::cout << "WINNER(S): ";
    for (auto winner_index : winners) {
        std::cout << games.prisoner_names[winner_index]
        << "(#" << winner_index + 1 << ") ";
    }
    std::cout << std::endl;

    for (int i = 0; i < games.prisoner_names.size(); i++) {
        std::cout << games.prisoner_names[i] << " | "
        << games.points.get()[i] << std::endl;
    }

}
