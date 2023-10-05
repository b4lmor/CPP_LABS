//
// Created by afox on 10/2/23.
//

#include "Choice.h"

#include <exception>

Choice get_choice_by_char(char c) {
    switch(c) {
        case 'C' : return Cooperate;
        case 'D' : return Defect;
        default : throw std::exception();
    }
}

std::string choice_to_string(Choice c) {
    switch (c) {
        case Cooperate: return "C";
        case Defect: return "D";
        default: throw std::exception();
    }
}
