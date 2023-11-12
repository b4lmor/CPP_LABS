//
// Created by afox on 10/28/23.
//

#ifndef LAB3_TASKFACTORY_H
#define LAB3_TASKFACTORY_H

#include <memory>
#include "../Task.h"

struct TaskFactory {
    template<typename T, typename... Args>
    std::shared_ptr<Task> create(Args&&... args) {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
};

#endif //LAB3_TASKFACTORY_H
