//
// Created by afox on 10/28/23.
//

#ifndef LAB3_MIXTASK_H
#define LAB3_MIXTASK_H

#include "../Task.h"

#define MIXTASK_INFO "mix - merge 2 wav files into one.\n configuration: mix $[index of input file] <from (seconds)> <to (seconds)>\n"

class MixTask : public Task {
private:
    std::string mix_file_path;
    int start;
    int end;
public:
    MixTask(std::string file_path,
            int s, int e,
            std::string mix_file_path);
    MixTask()=default;
    TaskType::TaskTypeEnum get_type() override { return TaskType::MIX; }
    void process() override;
    std::string get_info() override { return MIXTASK_INFO; }
};


#endif //LAB3_MIXTASK_H
