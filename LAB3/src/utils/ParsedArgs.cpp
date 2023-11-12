//
// Created by afox on 10/27/23.
//

#include "ParsedArgs.h"

#include "../exception/BadInputException.h"
#include <regex>

#define FLAG_PATTERN std::regex(R"(-[hc])")
#define CONFIG_PATTERN std::regex(R"(.+\.txt)")
#define WAV_PATTERN std::regex(R"(.+\.wav)")

static Mode parse_mode(std::string input_flag) {
    if (std::regex_match(input_flag, FLAG_PATTERN)) {
        return input_flag[1] == 'h'
               ? HELP
               : PROCESS;
    } else {
        throw BadInputException();
    }
}

static std::string parse_config_path(std::string input_config_path) {
    if (std::regex_match(input_config_path, CONFIG_PATTERN)) {
        return input_config_path;
    } else {
        throw BadInputException();
    }
}

static std::string parse_wave_file_path(std::string input_wave_file_path) {
    if (std::regex_match(input_wave_file_path, WAV_PATTERN)) {
        return input_wave_file_path;
    } else {
        throw BadInputException();
    }
}

ParsedArgs::ParsedArgs(int argc, char *argv[]) {
    if (argc <= 1) {
        throw BadInputException();
    }

    mode = parse_mode(argv[1]);

    if (mode != HELP) {

        if (argc < 5) {
            throw BadInputException();
        }

        config_file_path = parse_config_path(argv[2]);
        output_file_path = parse_wave_file_path(argv[3]);

        for (int i = 4; i < argc; i++) {
            input_file_paths.push_back(
                    parse_wave_file_path(argv[i])
            );
        }

    }


}

std::vector<std::string> ParsedArgs::get_input_paths() {
    return input_file_paths;
}

std::string ParsedArgs::get_output_file_path() {
    return output_file_path;
}

std::string ParsedArgs::get_config_file_path() {
    return config_file_path;
}

Mode ParsedArgs::get_mode() {
    return mode;
}
