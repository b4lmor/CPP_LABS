//
// Created by afox on 10/28/23.
//

#include "ConfigReader.h"
#include "../utils/StringUtils.h"
#include "../soundprocessor/task/impl/MixTask.h"
#include "../soundprocessor/task/impl/MuteTask.h"
#include "../soundprocessor/task/impl/CompressTask.h"
#include "../soundprocessor/task/taskfactory/TaskFactory.h"
#include "../exception/BadInputException.h"

#include <fstream>
#include <vector>
#include <regex>

#define COMMENT_SYMBOL '#'
#define INPUT_INDEX_PATTERN std::regex(R"(\$\d+)")
#define NUMERIC_PATTERN std::regex(R"(\d+)")
#define PERCENTAGE_PATTERN std::regex(R"(\d+%)")

static void init_mixtask_parameters(
        const std::vector<std::string> &config_line_words,
        int *start, int *end, int *input_index) {

    if (config_line_words.size() < 2 || config_line_words.size() > 4) {
        throw BadInputException(); // TODO описать ошибки
    }

    if (!std::regex_match(config_line_words[1], INPUT_INDEX_PATTERN)) {
        throw BadInputException();
    }

    *input_index = std::stoi(config_line_words[1].substr(1)) - 1;

    if (config_line_words.size() > 2) {

        if (!std::regex_match(config_line_words[2], NUMERIC_PATTERN)) {
            throw BadInputException();
        }

        *start = std::stoi(config_line_words[2]);

    } else {
        *start = -1;
        *end = -1;
        return;
    }

    if (config_line_words.size() > 3) {

        if (!std::regex_match(config_line_words[3], NUMERIC_PATTERN)) {
            throw BadInputException();
        }

        *end = std::stoi(config_line_words[3]);

    } else {
        *end = -1;
    }
}

static void init_mutetask_parameters(
        const std::vector<std::string> &config_line_words,
        int *start, int *end) {

    if (config_line_words.size() < 2 || config_line_words.size() > 4) {
        throw BadInputException();
    }

    if (config_line_words.size() > 1) {

        if (!std::regex_match(config_line_words[1], NUMERIC_PATTERN)) {
            BadInputException();
        }

        *start = std::stoi(config_line_words[1]);

    } else {
        *start = -1;
        *end = -1;
        return;
    }

    if (config_line_words.size() > 2) {

        if (!std::regex_match(config_line_words[2], NUMERIC_PATTERN)) {
            throw BadInputException();
        }

        *end = std::stoi(config_line_words[2]);

    } else {
        *end = -1;
    }
}

static void init_compresstask_parameters(
        const std::vector<std::string> &config_line_words,
        int *percentage) {

    if (config_line_words.size() != 2) {
        throw BadInputException();
    }

    if (!std::regex_match(config_line_words[1], PERCENTAGE_PATTERN)) {
        throw BadInputException();
    }

    *percentage = std::stoi(
            config_line_words[1].substr(0, config_line_words.size())
    );
}

std::queue<std::shared_ptr<Task>> ConfigReader::load_tasks(
        const std::string &config_file_path,
        const std::string &output_file_path,
        const std::vector<std::string> &input_file_paths) {

    std::ifstream config_file;
    config_file.open(config_file_path);

    if (!config_file.is_open()) {
        throw IOException();
    }

    std::queue<std::shared_ptr<Task>> tasks;

    std::string buffer;

    while (!config_file.eof()) {
        getline(config_file, buffer);

        if (buffer[0] == COMMENT_SYMBOL || buffer.empty()) {
            continue;
        }

        std::vector<std::string> config_line_words;
        StringUtils::split(buffer, config_line_words);

        if (config_line_words.empty()) {
            BadInputException();
        }

        TaskType::TaskTypeEnum task_type = TaskType::get_task_by_name(
                config_line_words[0]
        );

        TaskFactory factory;
        int start;
        int end;

        switch (task_type) { // TODO: validation for start, end, index, percentage

            case TaskType::MIX:
                int input_index;
                init_mixtask_parameters(config_line_words,
                                        &start,
                                        &end,
                                        &input_index);
                tasks.push(factory.create<MixTask>(
                        output_file_path,
                        start, end,
                        input_file_paths[input_index])
                );
                break;
            case TaskType::MUTE:
                init_mutetask_parameters(config_line_words,
                                         &start,
                                         &end);
                tasks.push(factory.create<MuteTask>(
                        output_file_path,
                        start, end)
                );
                break;
            case TaskType::COMPRESS:
                int percentage;
                init_compresstask_parameters(config_line_words,
                                             &percentage);
                tasks.push(factory.create<CompressTask>(
                        output_file_path,
                        percentage)
                );
                break;
        }
    }

    return tasks;
}
