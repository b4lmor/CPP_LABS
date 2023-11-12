//
// Created by afox on 10/28/23.
//

#ifndef LAB3_MIXTASK_H
#define LAB3_MIXTASK_H


#include "../Task.h"

class MixTask : public Task {
private:
    std::string mix_file_path;
    int start;
    int end;
public:
    MixTask(std::string file_path,
            int s, int e,
            std::string mix_file_path);
    TaskType::TaskTypeEnum get_type() override { return TaskType::MIX; }
    void process() override;
    std::string get_info() override { return ""; }
};


#endif //LAB3_MIXTASK_H
