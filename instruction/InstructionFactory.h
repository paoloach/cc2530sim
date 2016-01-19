//
// Created by Paolo Achdjian on 11/24/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#ifndef CC2530SIM_ISTRUCTIONFACTORY_H
#define CC2530SIM_ISTRUCTIONFACTORY_H


#include <stdint.h>
#include <memory>
#include "../FlashMemory.h"
#include "../MemoryLocation.h"
#include "../XData.h"

class Instruction;

class InstructionFactory {
public:
    InstructionFactory(InstructionPointer & IP, FlashMemory & flashMemory,XData & xdata);
    std::shared_ptr<Instruction> decode(uint8_t i);
private:
    InstructionPointer & IP;
    FlashMemory & flashMemory;
    XData & xdata;
    std::vector<std::shared_ptr<Instruction>> decodeMap;
};


#endif //CC2530SIM_ISTRUCTIONFACTORY_H
