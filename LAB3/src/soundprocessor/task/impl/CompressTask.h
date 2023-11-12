//
// Created by afox on 10/29/23.
//

#ifndef LAB3_COMPRESSTASK_H
#define LAB3_COMPRESSTASK_H


#include "../Task.h"

class CompressTask : public Task {
private:
    int percentage;
public:
    CompressTask(std::string file_path,
                 int percentage);
    TaskType::TaskTypeEnum get_type() override { return TaskType::COMPRESS; }
    void process() override;
    std::string get_info() override { return ""; }
};


#endif //LAB3_COMPRESSTASK_H
