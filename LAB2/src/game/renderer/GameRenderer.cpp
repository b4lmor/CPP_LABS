//
// Created by afox on 10/2/23.
//

#include "GameRenderer.h"
#include <iostream>
#include <algorithm>

void render_round(int total1, int total2, int total3,
                  int income1, int income2, int income3,
                  Choice choice1, Choice choice2, Choice choice3,
                  const std::string& name1, const std::string& name2, const std::string& name3,
                  int round) {
    std::cout << "round #"<< round + 1 << std::endl;
    std::cout << name1 << " | " << choice_to_string(choice1) << " | " << total1 << " (+" << income1 << ")" << std::endl;
    std::cout << name2 << " | " << choice_to_string(choice2) << " | " << total2 << " (+" << income2 << ")" << std::endl;
    std::cout << name3 << " | " << choice_to_string(choice3) << " | " << total3 << " (+" << income3 << ")" << std::endl;
    getchar();
}

void render_game_results(int total1, int total2, int total3,
                         const std::string& name1, const std::string& name2, const std::string& name3,
                         int rounds) {
    std::cout << "rounds: " << rounds << std::endl;
    std::cout << name1 << " | " << total1 << std::endl;
    std::cout << name2 << " | " << total2 << std::endl;
    std::cout << name3 << " | " << total3 << '\n' << std::endl;
}

void render_tournament_results(const std::vector<std::string> & prisoner_names,
                               int * points) {
    int winner_index = (int) std::distance(points,std::max_element(points, points + prisoner_names.size()));
    std::cout << "WINNER: " << prisoner_names[winner_index] << " (#" << winner_index + 1 << ")" << std::endl;
    for (int i = 0; i < prisoner_names.size(); i++) {
        std::cout << prisoner_names[i] << " | " << points[i] << std::endl;
    }
}

