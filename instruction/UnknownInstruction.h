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
    UnknownInstruction(InstructionFactory &instructionFactory, uint8_t OP,  uint32_t &IP):instructionFactory(instructionFactory),OP(OP),IP(IP){};
    virtual ~UnknownInstruction() = default;

public:
    virtual std::shared_ptr<Instruction> cycle() override;
private:
    InstructionFactory &instructionFactory;
    uint8_t OP;
    uint32_t &IP;

};


#endif //CC2530SIM_UNKNOWNINSTRUCTION_H
