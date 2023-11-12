//
// Created by afox on 10/28/23.
//

#include "StringUtils.h"

#define SEPARATOR ' '

void StringUtils::split(const std::string &line, std::vector<std::string> &out) {
    std::string to_push;

    for (char c: line) {
        if (c != SEPARATOR) {
            to_push.push_back(c);

        } else {
            if (!to_push.empty()) {
                out.push_back(to_push);
            }

            to_push.clear();
        }
    }

    if (!to_push.empty()) {
        out.push_back(to_push);
    }
}
