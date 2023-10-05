//
// Created by afox on 10/1/23.
//

#ifndef LAB2_GAMEFACTORY_H
#define LAB2_GAMEFACTORY_H

#include "AGame.h"
#include "../utils/enum/GameMode.h"
#include "../utils/GameArgs.h"

AGame * get_game_by_args(GameArgs args);

#endif //LAB2_GAMEFACTORY_H
