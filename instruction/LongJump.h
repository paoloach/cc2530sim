//
// Created by Paolo Achdjian on 11/24/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#ifndef CC2530SIM_LONGJUMP_H
#define CC2530SIM_LONGJUMP_H

#include "../FlashMemory.h"
#include "Instruction.h"
#include "InstructionFactory.h"

class LongJump: public Instruction {
public:
    LongJump(InstructionFactory &instructionFactory, uint32_t &IP, FlashMemory &flashMemory) : instructionFactory(
    instructionFactory), IP(IP), flashMemory(flashMemory) ,cycleCounter(3){ }

    virtual ~LongJump() = default;

public:
    virtual std::shared_ptr<Instruction> cycle() override;

private:
    InstructionFactory &instructionFactory;
    uint32_t &IP;
    FlashMemory &flashMemory;
    int cycleCounter;
};


#endif //CC2530SIM_LONGJUMP_H
