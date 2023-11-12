//
// Created by afox on 10/28/23.
//

#include "SoundProcessor.h"

#include <utility>
#include <queue>
#include <memory>

static inline void copy_file(const std::string& source_file_path,
                             const std::string& dest_file_path) {
    std::ifstream source(source_file_path);
    std::ofstream dest(dest_file_path);
    if (!source || !dest) {
        throw IOException();
    }
    dest << source.rdbuf();
}

SoundProcessor::SoundProcessor(std::string out_path, std::vector<std::string> input_paths) {
    output_file_path = std::move(out_path);
    input_file_paths = std::move(input_paths);
}

void SoundProcessor::process(const std::string& config_file_path) {
    copy_file(input_file_paths[0], output_file_path);

    std::queue<std::shared_ptr<Task>> tasks = ConfigReader::load_tasks(
            config_file_path,
            output_file_path,
            input_file_paths
            );

    while (!tasks.empty()) {
        tasks.front()->process();
        tasks.pop();
    }
}
