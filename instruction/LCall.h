//
// Created by Paolo Achdjian on 11/30/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#ifndef CC2530SIM_LCALL_H
#define CC2530SIM_LCALL_H

#include "../FlashMemory.h"
#include "Instruction.h"
#include "InstructionFactory.h"

class LCall : public Instruction{
public:
    LCall(InstructionFactory &instructionFactory, uint32_t &IP, FlashMemory &flashMemory, XData & xdata, MemoryLocation & SP) : instructionFactory(
            instructionFactory), IP(IP), flashMemory(flashMemory), SP(SP),xdata(xdata), cycleCounter(6){ }

    virtual ~LCall() = default;

public:
    virtual std::shared_ptr<Instruction> cycle() override;

private:
    InstructionFactory &instructionFactory;
    uint32_t &IP;
    FlashMemory &flashMemory;
    MemoryLocation & SP;
    XData & xdata;
    int cycleCounter;
};


#endif //CC2530SIM_LCALL_H
