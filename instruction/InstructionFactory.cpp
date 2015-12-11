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

    decodeMap[2] = std::make_shared<InstrTempl<Instructions::LJMP>>(*this, IP, flashMemory,xdata);
    decodeMap[0x12] = std::make_shared<InstrTempl<Instructions::LCALL>>(*this, IP, flashMemory,xdata);
    decodeMap[0x22] = std::make_shared<InstrTempl<Instructions::RET>>(*this, IP, flashMemory,xdata);
    decodeMap[0x44] = std::make_shared<InstrTempl<Instructions::ORL_A_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x54] = std::make_shared<InstrTempl<Instructions::ANL_A_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x75] = std::make_shared<InstrTempl<Instructions::MOV_DATA_DIRECT>>(*this, IP, flashMemory,xdata);

    decodeMap[0x78] = std::make_shared<InstrTempl<Instructions::MOV_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x79] = std::make_shared<InstrTempl<Instructions::MOV_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x7A] = std::make_shared<InstrTempl<Instructions::MOV_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x7B] = std::make_shared<InstrTempl<Instructions::MOV_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x7C] = std::make_shared<InstrTempl<Instructions::MOV_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x7D] = std::make_shared<InstrTempl<Instructions::MOV_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x7E] = std::make_shared<InstrTempl<Instructions::MOV_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x7F] = std::make_shared<InstrTempl<Instructions::MOV_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0xB8] = std::make_shared<InstrTempl<Instructions::CJNE_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0xB9] = std::make_shared<InstrTempl<Instructions::CJNE_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0xBA] = std::make_shared<InstrTempl<Instructions::CJNE_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0xBB] = std::make_shared<InstrTempl<Instructions::CJNE_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0xBC] = std::make_shared<InstrTempl<Instructions::CJNE_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0xBD] = std::make_shared<InstrTempl<Instructions::CJNE_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0xBE] = std::make_shared<InstrTempl<Instructions::CJNE_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0xBF] = std::make_shared<InstrTempl<Instructions::CJNE_RN_DATA>>(*this, IP, flashMemory,xdata);

    decodeMap[0xE5] = std::make_shared<InstrTempl<Instructions::MOV_A_DIRECT>>(*this, IP, flashMemory,xdata);
    decodeMap[0xF5] = std::make_shared<InstrTempl<Instructions::MOV_DIRECT_A>>(*this, IP, flashMemory,xdata);

}

std::shared_ptr<Instruction> InstructionFactory::decode(uint8_t opcode) {
    return decodeMap[opcode];
}
