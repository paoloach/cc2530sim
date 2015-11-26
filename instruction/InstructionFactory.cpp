//
// Created by Paolo Achdjian on 11/24/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#include "InstructionFactory.h"
#include "Nop.h"

InstructionFactory::InstructionFactory(uint32_t &IP, FlashMemory &flashMemory) : IP(IP), flashMemory(flashMemory) {
    decodeMap.resize(255);
    decodeMap[0] = std::make_shared<Nop>(*this,IP,flashMemory);
}

std::shared_ptr<Instruction> InstructionFactory::decode(uint8_t opcode) {
    return decodeMap[opcode];
}
