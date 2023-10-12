//
// Created by afox on 10/2/23.
//

#ifndef LAB2_MYTYPES_H
#define LAB2_MYTYPES_H

#include <utility>
#include <vector>
#include "../enum/Choice.h"

typedef struct Move {
    Choice choice1;
    Choice choice2;
    Choice choice3;
    int points1;
    int points2;
    int points3;
public:
    Move(Choice c1, Choice c2, Choice c3, int p1, int p2, int p3) {
        choice1 = c1;
        choice2 = c2;
        choice3 = c3;
        points1 = p1;
        points2 = p2;
        points3 = p3;
    }
} move_t;

typedef struct history {
    std::string prisoner_name1;
    std::string prisoner_name2;
    std::string prisoner_name3;
    std::vector<move_t> moves;
    void add_move(move_t m) {
        moves.push_back(m);
    }
    void add_move(Choice c1, Choice c2, Choice c3, int p1, int p2, int p3) {
        moves.emplace_back(c1, c2, c3, p1, p2, p3);
    }
} history_t;

typedef struct games {
    std::vector<history_t> games_history;
    int * points = nullptr;
    std::vector<std::string> prisoner_names;
    void add_game_history(const history_t& h) {
        games_history.push_back(h);
    }
} games_t;

typedef std::tuple<Choice, Choice, Choice> choices_t;

typedef std::tuple<int, int, int> points_t;

#endif //LAB2_MYTYPES_H
