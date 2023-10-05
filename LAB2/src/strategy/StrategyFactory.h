//
// Created by afox on 10/2/23.
//

#ifndef LAB2_STRATEGYFACTORY_H
#define LAB2_STRATEGYFACTORY_H

#include "AStrategy.h"

#include <string>

AStrategy * get_strategy_by_id(const std::string & name);

#endif //LAB2_STRATEGYFACTORY_H
