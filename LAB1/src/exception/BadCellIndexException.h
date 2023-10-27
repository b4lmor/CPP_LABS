//
// Created by afox on 9/27/23.
//

#include "MyException.h"

class BadCellIndexException : public MyException {
public:
    BadCellIndexException() : MyException("Bad cell index") {};
};
