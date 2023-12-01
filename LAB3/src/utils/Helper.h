//
// Created by afox on 10/28/23.
//

#ifndef LAB3_HELPER_H
#define LAB3_HELPER_H

#include <iostream>
#include "../soundprocessor/task/taskfactory/TaskFactory.h"

inline void print_help() {

    auto tasks = TaskFactory::get_all_tasks();

    for (const auto & task : tasks) {
        std::cout << task->get_info() << std::endl;
    }
}

#endif //LAB3_HELPER_H
