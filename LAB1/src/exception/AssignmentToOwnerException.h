//
// Created by afox on 9/27/23.
//

#include "MyException.h"

class AssignmentToOwnerException : public MyException {
public:
    AssignmentToOwnerException() : MyException("Can't assign object to itself") {};
};
