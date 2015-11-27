//
// Created by Paolo Achdjian on 11/24/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#ifndef CC2530SIM_ISTRUCTIONFACTORY_H
#define CC2530SIM_ISTRUCTIONFACTORY_H


#include <stdint.h>
#include <memory>
#include "Instruction.h"
#include "../FlashMemory.h"
#include "../MemoryLocation.h"

class InstructionFactory {
public:
    InstructionFactory(uint32_t & IP, FlashMemory & flashMemory,std::vector<MemoryLocation> & xdata);
    std::shared_ptr<Instruction> decode(uint8_t i);
private:
    uint32_t & IP;
    FlashMemory & flashMemory;
    std::vector<MemoryLocation> & xdata;
    std::vector<std::shared_ptr<Instruction>> decodeMap;
};


#endif //CC2530SIM_ISTRUCTIONFACTORY_H
