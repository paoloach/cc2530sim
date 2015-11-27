//
// Created by Paolo Achdjian on 11/24/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#include "InstructionFactory.h"
#include "UnknownInstruction.h"
#include "Nop.h"
#include "LongJump.h"

InstructionFactory::InstructionFactory(uint32_t &IP, FlashMemory &flashMemory, std::vector<MemoryLocation> &xdata) : IP(
        IP), flashMemory(flashMemory), xdata(xdata) {
    decodeMap.resize(256);
    for (int i = 0; i < 256; i++) {
        decodeMap[i] = std::make_shared<UnknownInstruction>(*this, i, IP);
    }
    decodeMap[0] = std::make_shared<Nop>(*this, IP, flashMemory);
    decodeMap[2] = std::make_shared<LongJump>(*this, IP, flashMemory);
}

std::shared_ptr<Instruction> InstructionFactory::decode(uint8_t opcode) {
    return decodeMap[opcode];
}
