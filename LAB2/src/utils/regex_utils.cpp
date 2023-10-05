//
// Created by afox on 10/2/23.
//

#include "regex_utils.h"

bool compare_with_pattern(const std::string& text, const std::string& pattern) {
    std::regex regex_pattern(pattern);
    return std::regex_match(text, regex_pattern);
}

std::string replace_pattern(const std::string & text,
                            const std::string & pattern,
                            const std::string & replacement) {
    std::regex regex_pattern(pattern);
    return std::regex_replace(text, regex_pattern, replacement);
}
