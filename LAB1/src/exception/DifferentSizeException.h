//
// Created by afox on 9/27/23.
//

#include "MyException.h"

class DifferentSizeException : public MyException {
public:
    DifferentSizeException() : MyException("Can't do it with bit arrays with different sizes") {};
};
