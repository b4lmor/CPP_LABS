//
// Created by afox on 10/28/23.
//

#ifndef LAB3_MUTETASK_H
#define LAB3_MUTETASK_H


#include <string>
#include "../Task.h"

#define MUTETASK_INFO "mute - mute wav file time interval.\n configuration: mute <from (seconds)> <to (seconds)>\n"

class MuteTask : public Task {
private:
    int start;
    int end;
public:
    MuteTask(std::string file_path, int s, int e);
    MuteTask()=default;
    TaskType::TaskTypeEnum get_type() override { return TaskType::MUTE; }
    void process() override;
    std::string get_info() override { return MUTETASK_INFO; }
};


#endif //LAB3_MUTETASK_H
