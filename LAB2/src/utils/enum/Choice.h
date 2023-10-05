//
// Created by afox on 9/30/23.
//

#ifndef LAB2_CHOICE_H
#define LAB2_CHOICE_H

#include <string>

enum Choice {
    Cooperate = 0,
    Defect
};

Choice get_choice_by_char(char c);
std::string choice_to_string(Choice c);

#endif //LAB2_CHOICE_H
