//
// Created by afox on 10/26/23.
//

#include <gtest/gtest.h>
#include "../../src/strategy/impl/AltruistStrategy.h"
#include "../../src/strategy/impl/BetrayerStrategy.h"
#include "../../src/strategy/impl/RandomStrategy.h"
#include "../../src/strategy/impl/BonafideStrategy.h"
#include "../../src/strategy/impl/MimickerStrategy.h"
#include "../../src/strategy/impl/CombinedStrategy.h"

TEST(StrategyTest, AltruistStrategy) {
    AltruistStrategy altruistStrategy;
    history_t history;
    Choice choice = altruistStrategy.make_choice(0, history);

    ASSERT_EQ(choice, Cooperate);
}

TEST(StrategyTest, BetrayerStrategy) {
    BetrayerStrategy betrayerStrategy;
    history_t history;
    Choice choice = betrayerStrategy.make_choice(0, history);

    ASSERT_EQ(choice, Defect);
}

TEST(StrategyTest, RandomerStrategy) {
    RandomStrategy randomerStrategy;
    history_t history;
    Choice choice = randomerStrategy.make_choice(0, history);
}

TEST(StrategyTest, BonafideStrategy) {
    BonafideStrategy bonafideStrategy;
    history_t history;

    Choice choice = bonafideStrategy.make_choice(0, history);

    ASSERT_EQ(choice, Cooperate);

    history.add_move(Defect, Defect, Defect, 1, 1, 1);

    choice = bonafideStrategy.make_choice(0, history);

    ASSERT_EQ(choice, Defect);
}

TEST(StrategyTest, MimickerStrategy) {
    MimickerStrategy mimickerStrategy;
    history_t history;

    Choice choice = mimickerStrategy.make_choice(0, history);

    ASSERT_EQ(choice, Defect);

    history.add_move(Cooperate, Cooperate, Defect, 3, 3, 9);

    choice = mimickerStrategy.make_choice(0, history);

    ASSERT_EQ(choice, Defect);
}

TEST(StrategyTest, CombinedStrategy) {
    CombinedStrategy combinedStrategy;
    history_t history;
    for (int i = 0; i < 5; i++) {
        Choice choice = combinedStrategy.make_choice(0, history);
        history.add_move(Cooperate, Cooperate, Defect, 3, 3, 9);
    }
}
