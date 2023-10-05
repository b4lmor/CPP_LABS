//
// Created by afox on 9/29/23.
//

#ifndef LAB2_GAMEMODE_H
#define LAB2_GAMEMODE_H

#include <string>

enum class GameMode {
    DETAILED,
    FAST,
    TOURNAMENT
};

GameMode get_mode_by_string(std::string & str);

#endif //LAB2_GAMEMODE_H
