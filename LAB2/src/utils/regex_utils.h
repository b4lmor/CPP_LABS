//
// Created by afox on 10/2/23.
//

#ifndef LAB2_REGEX_UTILS_H
#define LAB2_REGEX_UTILS_H

#include <string>
#include <regex>

bool compare_with_pattern(const std::string & text, const std::string & pattern);

std::string replace_pattern(const std::string & text,
                            const std::string & pattern,
                            const std::string & replacement);



#endif //LAB2_REGEX_UTILS_H
