//
// Created by Paolo Achdjian on 11/23/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#ifndef CC2530SIM_CPU_H
#define CC2530SIM_CPU_H


#include "FlashMemory.h"
#include "MemoryLocation.h"
#include "instruction/InstructionFactory.h"
#include "XData.h"

class CPU {
public:
    CPU(FlashMemory & flashMemory1);
public:
    void click();
    void reset();
private:
    FlashMemory & flashMemory;
    XData xdata;
    uint32_t IP;
    InstructionFactory instructionFactory;
    std::shared_ptr<Instruction> currentInstruct;
};


#endif //CC2530SIM_CPU_H
