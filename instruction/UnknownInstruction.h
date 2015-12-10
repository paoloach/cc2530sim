//
// Created by Paolo Achdjian on 11/26/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#ifndef CC2530SIM_UNKNOWNINSTRUCTION_H
#define CC2530SIM_UNKNOWNINSTRUCTION_H

#include "Instruction.h"
#include "InstructionFactory.h"

class UnknownInstruction : public Instruction {
public:
    UnknownInstruction(uint8_t OP, InstructionFactory &instructionFactory, uint32_t &IP, FlashMemory &flashMemory, XData &xdata)
    : Instruction(instructionFactory, IP, flashMemory, xdata),OP(OP){ }
    virtual ~UnknownInstruction() = default;

public:
    virtual std::shared_ptr<Instruction> cycle() override;
private:
    uint8_t OP;
};


#endif //CC2530SIM_UNKNOWNINSTRUCTION_H
