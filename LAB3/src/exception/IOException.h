//
// Created by afox on 10/28/23.
//

#ifndef LAB3_IOEXCEPTION_H
#define LAB3_IOEXCEPTION_H

#include "MyException.h"

#define CAUSE "file error"

class IOException : public MyException {
public:
    IOException() : MyException(CAUSE) {};
};

#endif //LAB3_IOEXCEPTION_H
