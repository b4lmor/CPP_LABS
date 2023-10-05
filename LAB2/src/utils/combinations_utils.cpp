//
// Created by afox on 10/5/23.
//

#include "combinations_utils.h"

std::vector<std::vector<int>> get_3combinations(const std::vector<int>& arr) {
    std::vector<std::vector<int>> combinations;

    if (arr.size() < 3) {
        return combinations;
    }

    for (int i = 0; i < arr.size() - 2; i++) {
        for (int j = i + 1; j < arr.size() - 1; j++) {
            for (int k = j + 1; k < arr.size(); k++) {
                std::vector<int> combination;
                combination.push_back(arr[i]);
                combination.push_back(arr[j]);
                combination.push_back(arr[k]);
                combinations.push_back(combination);
            }
        }
    }
    return combinations;
}

std::vector<std::vector<int>> get_3combinations_of_interval(int range) {
    std::vector<int> interval;
    interval.reserve(range);
    for (int i = 0; i < range; i++) {
        interval.push_back(i);
    }
    return get_3combinations(interval);
}
