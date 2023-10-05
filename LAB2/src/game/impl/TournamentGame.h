//
// Created by afox on 10/5/23.
//

#ifndef LAB2_TOURNAMENTGAME_H
#define LAB2_TOURNAMENTGAME_H


#include "../AGame.h"

class TournamentGame : public AGame {
private:
    std::vector<std::string> prisoner_names;
    GameMatrix matrix;
    history_t history;
    int steps;
    std::string configs_dir_path;
public:
    TournamentGame(const std::vector<std::string> & p_names,
                 const GameMatrix & mtrx, int s, const std::string & cfg_path);
    void run_game() override;
};


#endif //LAB2_TOURNAMENTGAME_H
