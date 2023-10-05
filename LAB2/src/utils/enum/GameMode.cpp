//
// Created by afox on 10/4/23.
//

#include "GameMode.h"

#include <exception>

GameMode get_mode_by_string(std::string & str) {
        if (str == "detailed") {
            return GameMode::DETAILED;
        } else if (str == "fast") {
            return GameMode::FAST;
        } else if (str == "tournament") {
            return GameMode::TOURNAMENT;
        } else {
            throw std::exception();
        }
}
