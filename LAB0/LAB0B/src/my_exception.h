//
// Created by afox on 9/9/23.
//

#ifndef LAB0B_MY_EXCEPTION_H
#define LAB0B_MY_EXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class my_exception : public exception {
    string msg;
public:
    explicit my_exception(string m);

    string get_msg();
};

#endif //LAB0B_MY_EXCEPTION_H
