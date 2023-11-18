//
// Created by afox on 10/26/23.
//

#include <gtest/gtest.h>
#include "../../src/matrix/GameMatrix.h"
#include "../../src/prisoner/Prisoner.h"
#include "../../src/game/impl/DetailedGame.h"
#include "../../src/game/impl/FastGame.h"
#include "../../src/game/impl/TournamentGame.h"

#define CONFIG_PATH "/home/afox/Documents/Work/NSU/CPP_LABS/LAB2/resources/config"

TEST(GameTest, FastGame) {
    GameMatrix matrix;
    int steps = 3;
    Prisoner p1("altruist", 0, CONFIG_PATH);
    Prisoner p2("altruist", 1, CONFIG_PATH);
    Prisoner p3("betrayer", 2, CONFIG_PATH);

    FastGame game(p1, p2, p3, matrix, steps);

    games_t games = game.run_game();

    ASSERT_EQ(games.prisoner_names[0], "altruist");
    ASSERT_EQ(games.prisoner_names[1], "altruist");
    ASSERT_EQ(games.prisoner_names[2], "betrayer");

    ASSERT_EQ(games.games_history.size(), 1);

    history_t history = games.games_history[0];

    ASSERT_EQ(history.moves.size(), 3);

    ASSERT_EQ(history.moves[0].choice1, Cooperate);
    ASSERT_EQ(history.moves[0].choice2, Cooperate);
    ASSERT_EQ(history.moves[0].choice3, Defect);

    ASSERT_EQ(history.moves[1].choice1, Cooperate);
    ASSERT_EQ(history.moves[1].choice2, Cooperate);
    ASSERT_EQ(history.moves[1].choice3, Defect);

    ASSERT_EQ(history.moves[2].choice1, Cooperate);
    ASSERT_EQ(history.moves[2].choice2, Cooperate);
    ASSERT_EQ(history.moves[2].choice3, Defect);
}

TEST(GameTest, TournamentGame) {
    GameMatrix matrix;
    int steps = 2;
    std::vector<std::string> names;
    names.emplace_back("altruist");
    names.emplace_back("altruist");
    names.emplace_back("betrayer");
    names.emplace_back("betrayer");

    TournamentGame game(names, matrix, steps, "");

    games_t games = game.run_game();

    ASSERT_EQ(games.prisoner_names[0], "altruist");
    ASSERT_EQ(games.prisoner_names[1], "altruist");
    ASSERT_EQ(games.prisoner_names[2], "betrayer");
    ASSERT_EQ(games.prisoner_names[3], "betrayer");

    ASSERT_EQ(games.games_history.size(), 4);

    history_t history = games.games_history[0];

    ASSERT_EQ(history.moves.size(), 2);

    ASSERT_EQ(history.moves[0].choice1, Cooperate);
    ASSERT_EQ(history.moves[0].choice2, Cooperate);
    ASSERT_EQ(history.moves[0].choice3, Defect);

    ASSERT_EQ(history.moves[1].choice1, Cooperate);
    ASSERT_EQ(history.moves[1].choice2, Cooperate);
    ASSERT_EQ(history.moves[1].choice3, Defect);

}
