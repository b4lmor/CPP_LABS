//
// Created by afox on 10/28/23.
//

#ifndef LAB3_SOUNDPROCESSOR_H
#define LAB3_SOUNDPROCESSOR_H

#include <vector>
#include <queue>
#include <string>
#include <memory>
#include "../configreader/ConfigReader.h"

class SoundProcessor {
private:
    std::vector<std::string> input_file_paths;
    std::string output_file_path;

public:
    SoundProcessor(std::string out_path, std::vector<std::string> input_paths);
    void process(const std::string& config_file_path);
};


#endif //LAB3_SOUNDPROCESSOR_H
