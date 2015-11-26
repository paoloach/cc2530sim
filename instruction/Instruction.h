//
// Created by Paolo Achdjian on 11/23/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#ifndef CC2530SIM_INSTRUCTION_H
#define CC2530SIM_INSTRUCTION_H


#include <memory>

class Instruction {
public:
    virtual std::shared_ptr<Instruction> cycle() = 0;
};


#endif //CC2530SIM_INSTRUCTION_H
