//
// Created by afox on 10/26/23.
//
#include <gtest/gtest.h>
#include "../../src/matrix/GameMatrix.h"

TEST(MatrixTest, readMatrix) {
    GameMatrix matrix;
    int points1 = matrix.get_points_for_concrete(Defect, Defect, Defect, 0);
    int points2 = matrix.get_points_for_concrete(Defect, Defect, Defect, 1);
    int points3 = matrix.get_points_for_concrete(Defect, Defect, Defect, 2);

    ASSERT_EQ(points1, points2);
    ASSERT_EQ(points3, points3);
    ASSERT_EQ(points3, 1);
}
