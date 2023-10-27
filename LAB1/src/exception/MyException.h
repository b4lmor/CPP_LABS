//
// Created by afox on 9/27/23.
//

#ifndef LAB1_MYEXCEPTION_H
#define LAB1_MYEXCEPTION_H

#include <string>
#include <utility>

class MyException : public std::exception{
    std::string msg;
public:
    explicit MyException(std::string m) : msg(std::move(m)) {};
    std::string get_message() { return msg; }
};

#endif //LAB1_MYEXCEPTION_H
