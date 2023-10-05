//
// Created by afox on 10/2/23.
//

#ifndef LAB2_GAMERENDERER_H
#define LAB2_GAMERENDERER_H

#include "../../utils/enum/Choice.h"

#include <string>
#include <vector>

void render_round(int total1, int total2, int total3,
                  int income1, int income2, int income3,
                  Choice choice1, Choice choice2, Choice choice3,
                  const std::string& name1, const std::string& name2, const std::string& name3,
                  int round);

void render_game_results(int total1, int total2, int total3,
                         const std::string& name1, const std::string& name2, const std::string& name3,
                         int rounds);

void render_tournament_results(const std::vector<std::string>& prisoner_names, int * points);

#endif //LAB2_GAMERENDERER_H
