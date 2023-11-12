//
// Created by afox on 10/28/23.
//

#ifndef LAB3_TASK_H
#define LAB3_TASK_H

#include "TaskType.h"
#include <fstream>
#include "../../exception/IOException.h"

#define TEMPORARY_FILE_PATH "/home/afox/Documents/Work/NSU/CPP_LABS/LAB3/resources/tmp.wav"

class Task {
protected:
    std::string file_path;
    static void copy_file(const std::string& source_file_path,
                   const std::string& dest_file_path) {
        std::ifstream source(source_file_path);
        std::ofstream dest(dest_file_path);
        if (!source || !dest) {
            throw IOException();
        }
        dest << source.rdbuf();
    }
public:
    virtual void process() = 0;
    virtual TaskType::TaskTypeEnum get_type() = 0;
    virtual std::string get_info() = 0;
    virtual ~Task() = default;
};

#endif //LAB3_TASK_H
