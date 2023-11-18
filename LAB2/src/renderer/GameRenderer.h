//
// Created by afox on 10/13/23.
//

#ifndef LAB2_GAMERENDERER_H
#define LAB2_GAMERENDERER_H

#include "../utils/my_types/MyTypes.h"
#include "../utils/GameArgs.h"

class GameRenderer {
public:
    static void render_game(GameArgs args, const games_t& games);
    static void render_round(int step, const move_t& move, int income1, int income2, int income3,
                             const std::string& name1, const std::string& name2, const std::string& name3);
private:
    static void render_detailed_game(games_t games);
    static void render_fast_game(games_t games);
    static void render_tournament_game(games_t games);
    static void render_results(const move_t& last_move, int steps,
                               const std::string& name1, const std::string& name2, const std::string& name3);
};


#endif //LAB2_GAMERENDERER_H
