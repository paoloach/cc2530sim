//
// Created by Paolo Achdjian on 11/24/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#include "InstructionFactory.h"
#include "UnknownInstruction.h"

InstructionFactory::InstructionFactory(uint32_t &IP, FlashMemory &flashMemory, XData &xdata) : IP(
        IP), flashMemory(flashMemory), xdata(xdata) {
    decodeMap.resize(256);
    for (int i = 0; i < 256; i++) {
        decodeMap[i] = std::make_shared<UnknownInstruction>(i, *this, IP, flashMemory,xdata);
    }
    decodeMap[0] = std::make_shared<InstrTempl<Instructions::NOP>>(*this, IP, flashMemory,xdata);
    decodeMap[0x75] = std::make_shared<InstrTempl<Instructions::MOV_DATA_DIRECT>>(*this, IP, flashMemory,xdata);
    decodeMap[2] = std::make_shared<InstrTempl<Instructions::LJMP>>(*this, IP, flashMemory,xdata);
    decodeMap[0x12] = std::make_shared<InstrTempl<Instructions::LCALL>>(*this, IP, flashMemory,xdata);
    decodeMap[0x54] = std::make_shared<InstrTempl<Instructions::MOV_A_DIRECT>>(*this, IP, flashMemory,xdata);

}

std::shared_ptr<Instruction> InstructionFactory::decode(uint8_t opcode) {
    return decodeMap[opcode];
}
