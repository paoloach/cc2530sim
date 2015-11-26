//
// Created by Paolo Achdjian on 11/24/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#ifndef CC2530SIM_NOP_H
#define CC2530SIM_NOP_H


#include "../FlashMemory.h"
#include "Instruction.h"
#include "InstructionFactory.h"

class Nop : public Instruction {
public:
    Nop(InstructionFactory &instructionFactory, uint32_t &IP, FlashMemory &flashMemory) : instructionFactory(
            instructionFactory), IP(IP), flashMemory(flashMemory) { }

    virtual ~Nop() = default;

public:
    virtual std::shared_ptr<Instruction> cycle() override;

private:
    InstructionFactory &instructionFactory;
    uint32_t &IP;
    FlashMemory &flashMemory;
};


#endif //CC2530SIM_NOP_H
