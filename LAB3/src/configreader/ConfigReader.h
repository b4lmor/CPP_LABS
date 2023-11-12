//
// Created by afox on 10/28/23.
//

#ifndef LAB3_CONFIGREADER_H
#define LAB3_CONFIGREADER_H

#include <string>
#include <queue>
#include <memory>
#include <vector>
#include "../soundprocessor/task/Task.h"

class ConfigReader {
public:
    static std::queue<std::shared_ptr<Task>> load_tasks(
            const std::string &config_file_path,
            const std::string &output_file_path,
            const std::vector<std::string>& input_file_paths);
};


#endif //LAB3_CONFIGREADER_H
