//
// Created by afox on 10/28/23.
//

#ifndef LAB3_TASKFACTORY_H
#define LAB3_TASKFACTORY_H

#include <memory>
#include "../Task.h"
#include "../impl/CompressTask.h"
#include "../impl/MuteTask.h"
#include "../impl/MixTask.h"

struct TaskFactory {
    template<typename T, typename... Args>
    std::shared_ptr<Task> create(Args&&... args) {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    static std::vector<std::unique_ptr<Task>> get_all_tasks() {
        std::vector<std::unique_ptr<Task>> tasks;

        tasks.push_back(std::make_unique<MuteTask>());
        tasks.push_back(std::make_unique<MixTask>());
        tasks.push_back(std::make_unique<CompressTask>());

        return tasks;
    }
};

#endif //LAB3_TASKFACTORY_H
