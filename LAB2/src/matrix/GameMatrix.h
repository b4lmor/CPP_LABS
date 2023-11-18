//
// Created by afox on 9/30/23.
//

#ifndef LAB2_GAMEMATRIX_H
#define LAB2_GAMEMATRIX_H

#include <set>
#include <string>

#include "../utils/enum/Choice.h"
#include "../utils/my_types/MyTypes.h"

#define MATRIX_LINE_REGEX R"(([CD])  ([CD])  ([CD])  =>  (\d+)  (\d+)  (\d+))"

class GameMatrix {
    int matrix[2][2][2][3] = { 0 };
    static void update_matrix(
            int arr[2][2][2][3], std::string input, std::set<int> * lines);
public:
    explicit GameMatrix(std::string file_path);
    GameMatrix();
    int get_points_for_concrete(Choice c1, Choice c2, Choice c3, int prisoner_ind);
};

#endif //LAB2_GAMEMATRIX_H
