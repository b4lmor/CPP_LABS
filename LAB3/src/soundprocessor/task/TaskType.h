//
// Created by afox on 10/28/23.
//

#ifndef LAB3_TASKTYPE_H
#define LAB3_TASKTYPE_H

#include <string>

#define MUTE_STRING_REPRESENTATION "mute"
#define MIX_STRING_REPRESENTATION "mix"
#define COMPRESS_STRING_REPRESENTATION "compress"

class TaskType {
public:
    enum TaskTypeEnum {
        MUTE,
        MIX,
        COMPRESS
    };

    static TaskTypeEnum get_task_by_name(const std::string &task_name) {
        if (task_name == MUTE_STRING_REPRESENTATION) {
            return MUTE;
        } else if (task_name == MIX_STRING_REPRESENTATION) {
            return MIX;
        } else if (task_name == COMPRESS_STRING_REPRESENTATION) {
            return COMPRESS;
        } else {
            throw std::exception();
        }
    }
};

#endif //LAB3_TASKTYPE_H
