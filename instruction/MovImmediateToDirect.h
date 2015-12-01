//
// Created by Paolo Achdjian on 11/26/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#ifndef CC2530SIM_MOVIMMEDIATETODIRECT_H
#define CC2530SIM_MOVIMMEDIATETODIRECT_H

#include "../FlashMemory.h"
#include "Instruction.h"
#include "InstructionFactory.h"

class MovImmediateToDirect: public Instruction {
public:
    MovImmediateToDirect(InstructionFactory &instructionFactory, uint32_t &IP, FlashMemory &flashMemory, XData & xdata) : instructionFactory(
            instructionFactory), IP(IP), flashMemory(flashMemory), xdata(xdata), cycleCounter(3){ }

    virtual ~MovImmediateToDirect() = default;

public:
    virtual std::shared_ptr<Instruction> cycle() override;

private:
    InstructionFactory &instructionFactory;
    uint32_t &IP;
    FlashMemory &flashMemory;
    XData & xdata;
    int cycleCounter;
};


#endif //CC2530SIM_MOVIMMEDIATETODIRECT_H
