//
// Created by afox on 9/9/23.
//

#include "my_exception.h"

#include <utility>

my_exception::my_exception(std::string m) {
    msg = std::move(m);
}

string my_exception::get_msg() {
    return msg;
}
