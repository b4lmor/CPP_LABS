//
// Created by afox on 9/30/23.
//

#ifndef LAB2_GAMEMATRIX_H
#define LAB2_GAMEMATRIX_H

#include <map>
#include <tuple>
#include <string>

#include "../utils/enum/Choice.h"
#include "../utils/my_types/MyTypes.h"

#define MATRIX_LINE_REGEX R"(([CD]  [CD]  [CD]  =>  \d+  \d+  \d+))"

class GameMatrix {
    std::map<choices_t, points_t> matrix;
    points_t get_points(Choice c1, Choice c2, Choice c3);
    int get_points_for_first(Choice c1, Choice c2, Choice c3);
    int get_points_for_second(Choice c1, Choice c2, Choice c3);
    int get_points_for_third(Choice c1, Choice c2, Choice c3);
public:
    explicit GameMatrix(std::string file_path);
    GameMatrix();
    int get_points_for_concrete(Choice c1, Choice c2, Choice c3, int prisoner_ind);
};

#endif //LAB2_GAMEMATRIX_H
