//
// Created by afox on 10/28/23.
//

#ifndef LAB3_BADINPUTEXCEPTION_H
#define LAB3_BADINPUTEXCEPTION_H

#include "MyException.h"

#define CAUSE "bad input parameters, try '-h' if you need a help."

class BadInputException : public MyException {
public:
    BadInputException() : MyException(CAUSE) {};
};

#endif //LAB3_BADINPUTEXCEPTION_H
