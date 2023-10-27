//
// Created by afox on 9/27/23.
//

#include "MyException.h"

class BadBitPositionException : public MyException {
public:
    BadBitPositionException() : MyException("Bad bit position") {};
};
