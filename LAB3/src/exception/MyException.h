//
// Created by afox on 10/28/23.
//

#ifndef LAB3_MYEXCEPTION_H
#define LAB3_MYEXCEPTION_H

#include <string>
#include <utility>

class MyException : public std::exception {
    std::string cause;

public:
    explicit MyException(std::string c) : cause(std::move(c)) {};
    std::string get_cause() { return cause; }
};

#endif //LAB3_MYEXCEPTION_H
