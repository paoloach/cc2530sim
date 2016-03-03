//
// Created by Paolo Achdjian on 11/24/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#include <iostream>
#include "InstructionFactory.h"
#include "UnknownInstruction.h"

InstructionFactory::InstructionFactory(InstructionPointer &IP, FlashMemory &flashMemory, XData &xdata) : IP(
        IP), flashMemory(flashMemory), xdata(xdata) {
    decodeMap.resize(256);
    for (int i = 0; i < 256; i++) {
        decodeMap[i] = std::make_shared<UnknownInstruction>(i, *this, IP, flashMemory,xdata);
    }
    decodeMap[0x00] = std::make_shared<InstrTemp1<Instructions::NOP>>(*this, IP, flashMemory,xdata);
    decodeMap[0x01] = std::make_shared<InstrTemp3<Instructions::AJMP>>(*this, IP, flashMemory,xdata);
    decodeMap[0x02] = std::make_shared<InstrTempl<Instructions::LJMP>>(*this, IP, flashMemory,xdata);
    decodeMap[0x03] = std::make_shared<InstrTemp1<Instructions::RR_A>>(*this, IP, flashMemory,xdata);
    decodeMap[0x04] = std::make_shared<InstrTemp1<Instructions::INC_A>>(*this, IP, flashMemory,xdata);
    decodeMap[0x05] = std::make_shared<InstrTemp2<Instructions::INC_ADDR>>(*this, IP, flashMemory,xdata);
    decodeMap[0x06] = std::make_shared<InstrTemp2<Instructions::INC_AT_Rn>>(*this, IP, flashMemory,xdata);
    decodeMap[0x07] = std::make_shared<InstrTemp2<Instructions::INC_AT_Rn>>(*this, IP, flashMemory,xdata);
    decodeMap[0x08] = std::make_shared<InstrTemp1<Instructions::INC_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x09] = std::make_shared<InstrTemp1<Instructions::INC_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x0A] = std::make_shared<InstrTemp1<Instructions::INC_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x0B] = std::make_shared<InstrTemp1<Instructions::INC_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x0C] = std::make_shared<InstrTemp1<Instructions::INC_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x0D] = std::make_shared<InstrTemp1<Instructions::INC_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x0E] = std::make_shared<InstrTemp1<Instructions::INC_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x0F] = std::make_shared<InstrTemp1<Instructions::INC_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x10] = std::make_shared<InstrTemp4<Instructions::JBC>>(*this, IP, flashMemory,xdata);
    decodeMap[0x12] = std::make_shared<InstrTempl<Instructions::LCALL>>(*this, IP, flashMemory,xdata);

    decodeMap[0x14] = std::make_shared<InstrTemp1<Instructions::DEC_A>>(*this, IP, flashMemory,xdata);
    decodeMap[0x15] = std::make_shared<InstrTemp2<Instructions::DEC_ADDR>>(*this, IP, flashMemory,xdata);
    decodeMap[0x16] = std::make_shared<InstrTemp2<Instructions::DEC_AT_Rn>>(*this, IP, flashMemory,xdata);
    decodeMap[0x17] = std::make_shared<InstrTemp2<Instructions::DEC_AT_Rn>>(*this, IP, flashMemory,xdata);
    decodeMap[0x18] = std::make_shared<InstrTemp1<Instructions::DEC_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x19] = std::make_shared<InstrTemp1<Instructions::DEC_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x1A] = std::make_shared<InstrTemp1<Instructions::DEC_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x1B] = std::make_shared<InstrTemp1<Instructions::DEC_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x1C] = std::make_shared<InstrTemp1<Instructions::DEC_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x1D] = std::make_shared<InstrTemp1<Instructions::DEC_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x1E] = std::make_shared<InstrTemp1<Instructions::DEC_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x1F] = std::make_shared<InstrTemp1<Instructions::DEC_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x20] = std::make_shared<InstrTemp4<Instructions::JB>>(*this, IP, flashMemory,xdata);
    decodeMap[0x21] = std::make_shared<InstrTemp3<Instructions::AJMP>>(*this, IP, flashMemory,xdata);
    decodeMap[0x22] = std::make_shared<InstrTempl<Instructions::RET>>(*this, IP, flashMemory,xdata);
    decodeMap[0x23] = std::make_shared<InstrTempl<Instructions::RL_A>>(*this, IP, flashMemory,xdata);
    decodeMap[0x24] = std::make_shared<InstrTemp2<Instructions::ADD_A_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x25] = std::make_shared<InstrTemp2<Instructions::ADD_A_DIRECT>>(*this, IP, flashMemory,xdata);
    decodeMap[0x26] = std::make_shared<InstrTemp2<Instructions::ADD_A_AT_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x27] = std::make_shared<InstrTemp2<Instructions::ADD_A_AT_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x28] = std::make_shared<InstrTemp1<Instructions::ADD_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x29] = std::make_shared<InstrTemp1<Instructions::ADD_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x2A] = std::make_shared<InstrTemp1<Instructions::ADD_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x2B] = std::make_shared<InstrTemp1<Instructions::ADD_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x2C] = std::make_shared<InstrTemp1<Instructions::ADD_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x2D] = std::make_shared<InstrTemp1<Instructions::ADD_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x2E] = std::make_shared<InstrTemp1<Instructions::ADD_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x2F] = std::make_shared<InstrTemp1<Instructions::ADD_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x30] = std::make_shared<InstrTemp4<Instructions::JNB>>(*this, IP, flashMemory,xdata);
    decodeMap[0x34] = std::make_shared<InstrTemp2<Instructions::ADDC_A_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x35] = std::make_shared<InstrTemp2<Instructions::ADDC_A_DIRECT>>(*this, IP, flashMemory,xdata);
    decodeMap[0x36] = std::make_shared<InstrTemp2<Instructions::ADDC_A_AT_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x37] = std::make_shared<InstrTemp2<Instructions::ADDC_A_AT_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x38] = std::make_shared<InstrTemp1<Instructions::ADDC_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x39] = std::make_shared<InstrTemp1<Instructions::ADDC_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x3A] = std::make_shared<InstrTemp1<Instructions::ADDC_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x3B] = std::make_shared<InstrTemp1<Instructions::ADDC_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x3C] = std::make_shared<InstrTemp1<Instructions::ADDC_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x3D] = std::make_shared<InstrTemp1<Instructions::ADDC_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x3E] = std::make_shared<InstrTemp1<Instructions::ADDC_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x3F] = std::make_shared<InstrTemp1<Instructions::ADDC_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x40] = std::make_shared<InstrTemp3<Instructions::JC>>(*this, IP, flashMemory,xdata);
    decodeMap[0x41] = std::make_shared<InstrTemp3<Instructions::AJMP>>(*this, IP, flashMemory,xdata);
    decodeMap[0x44] = std::make_shared<InstrTempl<Instructions::ORL_A_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x50] = std::make_shared<InstrTemp3<Instructions::JNC>>(*this, IP, flashMemory,xdata);
    decodeMap[0x54] = std::make_shared<InstrTempl<Instructions::ANL_A_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x60] = std::make_shared<InstrTemp3<Instructions::JZ>>(*this, IP, flashMemory,xdata);
    decodeMap[0x61] = std::make_shared<InstrTemp3<Instructions::AJMP>>(*this, IP, flashMemory,xdata);
    decodeMap[0x70] = std::make_shared<InstrTemp3<Instructions::JNZ>>(*this, IP, flashMemory,xdata);
    decodeMap[0x73] = std::make_shared<InstrTempl<Instructions::JMP_A_DPTR>>(*this, IP, flashMemory,xdata);
    decodeMap[0x74] = std::make_shared<InstrTempl<Instructions::MOV_A_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x75] = std::make_shared<InstrTemp3<Instructions::MOV_DATA_DIRECT>>(*this, IP, flashMemory,xdata);

    decodeMap[0x78] = std::make_shared<InstrTempl<Instructions::MOV_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x79] = std::make_shared<InstrTempl<Instructions::MOV_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x7A] = std::make_shared<InstrTempl<Instructions::MOV_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x7B] = std::make_shared<InstrTempl<Instructions::MOV_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x7C] = std::make_shared<InstrTempl<Instructions::MOV_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x7D] = std::make_shared<InstrTempl<Instructions::MOV_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x7E] = std::make_shared<InstrTempl<Instructions::MOV_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x7F] = std::make_shared<InstrTempl<Instructions::MOV_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x80] = std::make_shared<InstrTempl<Instructions::SJMP>>(*this, IP, flashMemory,xdata);
    decodeMap[0x81] = std::make_shared<InstrTemp3<Instructions::AJMP>>(*this, IP, flashMemory,xdata);
    decodeMap[0x85] = std::make_shared<InstrTemp4<Instructions::MOV_DIRECT_DIRECT>>(*this, IP, flashMemory,xdata);
    decodeMap[0x88] = std::make_shared<InstrTemp3<Instructions::MOV_DIRECT_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x89] = std::make_shared<InstrTemp3<Instructions::MOV_DIRECT_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x8A] = std::make_shared<InstrTemp3<Instructions::MOV_DIRECT_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x8B] = std::make_shared<InstrTemp3<Instructions::MOV_DIRECT_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x8C] = std::make_shared<InstrTemp3<Instructions::MOV_DIRECT_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x8D] = std::make_shared<InstrTemp3<Instructions::MOV_DIRECT_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x8E] = std::make_shared<InstrTemp3<Instructions::MOV_DIRECT_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x8F] = std::make_shared<InstrTemp3<Instructions::MOV_DIRECT_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x90] = std::make_shared<InstrTempl<Instructions::MOV_DPTR_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x93] = std::make_shared<InstrTemp3<Instructions::MOVC_A_DPTR>>(*this, IP, flashMemory,xdata);
    decodeMap[0x94] = std::make_shared<InstrTemp2<Instructions::SUBB_A_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0x95] = std::make_shared<InstrTemp2<Instructions::SUBB_A_DIRECT>>(*this, IP, flashMemory,xdata);
    decodeMap[0x96] = std::make_shared<InstrTemp2<Instructions::SUBB_A_AT_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x97] = std::make_shared<InstrTemp2<Instructions::SUBB_A_AT_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x98] = std::make_shared<InstrTemp1<Instructions::SUBB_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x99] = std::make_shared<InstrTemp1<Instructions::SUBB_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x9A] = std::make_shared<InstrTemp1<Instructions::SUBB_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x9B] = std::make_shared<InstrTemp1<Instructions::SUBB_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x9C] = std::make_shared<InstrTemp1<Instructions::SUBB_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x9D] = std::make_shared<InstrTemp1<Instructions::SUBB_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x9E] = std::make_shared<InstrTemp1<Instructions::SUBB_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0x9F] = std::make_shared<InstrTemp1<Instructions::SUBB_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xA1] = std::make_shared<InstrTemp3<Instructions::AJMP>>(*this, IP, flashMemory,xdata);
    decodeMap[0xA2] = std::make_shared<InstrTemp2<Instructions::MOV_C_BIT_ADDR>>(*this, IP, flashMemory,xdata);
    decodeMap[0xA3] = std::make_shared<InstrTemp1<Instructions::INC_DPTR>>(*this, IP, flashMemory,xdata);
    decodeMap[0xA8] = std::make_shared<InstrTemp4<Instructions::MOV_RN_DIRECT>>(*this, IP, flashMemory,xdata);
    decodeMap[0xA9] = std::make_shared<InstrTemp4<Instructions::MOV_RN_DIRECT>>(*this, IP, flashMemory,xdata);
    decodeMap[0xAA] = std::make_shared<InstrTemp4<Instructions::MOV_RN_DIRECT>>(*this, IP, flashMemory,xdata);
    decodeMap[0xAB] = std::make_shared<InstrTemp4<Instructions::MOV_RN_DIRECT>>(*this, IP, flashMemory,xdata);
    decodeMap[0xAC] = std::make_shared<InstrTemp4<Instructions::MOV_RN_DIRECT>>(*this, IP, flashMemory,xdata);
    decodeMap[0xAD] = std::make_shared<InstrTemp4<Instructions::MOV_RN_DIRECT>>(*this, IP, flashMemory,xdata);
    decodeMap[0xAE] = std::make_shared<InstrTemp4<Instructions::MOV_RN_DIRECT>>(*this, IP, flashMemory,xdata);
    decodeMap[0xAF] = std::make_shared<InstrTemp4<Instructions::MOV_RN_DIRECT>>(*this, IP, flashMemory,xdata);
    decodeMap[0xB8] = std::make_shared<InstrTempl<Instructions::CJNE_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0xB9] = std::make_shared<InstrTempl<Instructions::CJNE_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0xBA] = std::make_shared<InstrTempl<Instructions::CJNE_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0xBB] = std::make_shared<InstrTempl<Instructions::CJNE_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0xBC] = std::make_shared<InstrTempl<Instructions::CJNE_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0xBD] = std::make_shared<InstrTempl<Instructions::CJNE_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0xBE] = std::make_shared<InstrTempl<Instructions::CJNE_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0xBF] = std::make_shared<InstrTempl<Instructions::CJNE_RN_DATA>>(*this, IP, flashMemory,xdata);
    decodeMap[0xC0] = std::make_shared<InstrTemp4<Instructions::PUSH>>(*this, IP, flashMemory,xdata);
    decodeMap[0xC1] = std::make_shared<InstrTemp3<Instructions::AJMP>>(*this, IP, flashMemory,xdata);
    decodeMap[0xC2] = std::make_shared<InstrTemp3<Instructions::CLR_BIT>>(*this, IP, flashMemory,xdata);
    decodeMap[0xC3] = std::make_shared<InstrTemp1<Instructions::CLR_C>>(*this, IP, flashMemory,xdata);
    decodeMap[0xC5] = std::make_shared<InstrTemp3<Instructions::XCH_A_DIRECT>>(*this, IP, flashMemory,xdata);
    decodeMap[0xC6] = std::make_shared<InstrTemp3<Instructions::XCH_A_AT_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xC7] = std::make_shared<InstrTemp3<Instructions::XCH_A_AT_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xC8] = std::make_shared<InstrTemp2<Instructions::XCH_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xC9] = std::make_shared<InstrTemp2<Instructions::XCH_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xCA] = std::make_shared<InstrTemp2<Instructions::XCH_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xCB] = std::make_shared<InstrTemp2<Instructions::XCH_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xCC] = std::make_shared<InstrTemp2<Instructions::XCH_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xCD] = std::make_shared<InstrTemp2<Instructions::XCH_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xCE] = std::make_shared<InstrTemp2<Instructions::XCH_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xCF] = std::make_shared<InstrTemp2<Instructions::XCH_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xD0] = std::make_shared<InstrTemp3<Instructions::POP>>(*this, IP, flashMemory,xdata);
    decodeMap[0xD8] = std::make_shared<InstrTempl<Instructions::DJNZ_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xD9] = std::make_shared<InstrTempl<Instructions::DJNZ_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xDA] = std::make_shared<InstrTempl<Instructions::DJNZ_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xDB] = std::make_shared<InstrTempl<Instructions::DJNZ_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xDC] = std::make_shared<InstrTempl<Instructions::DJNZ_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xDD] = std::make_shared<InstrTempl<Instructions::DJNZ_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xDE] = std::make_shared<InstrTempl<Instructions::DJNZ_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xDF] = std::make_shared<InstrTempl<Instructions::DJNZ_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xE1] = std::make_shared<InstrTemp3<Instructions::AJMP>>(*this, IP, flashMemory,xdata);
    decodeMap[0xE4] = std::make_shared<InstrTempl<Instructions::CLR_A>>(*this, IP, flashMemory,xdata);
    decodeMap[0xE5] = std::make_shared<InstrTemp2<Instructions::MOV_A_DIRECT>>(*this, IP, flashMemory,xdata);
    decodeMap[0xE6] = std::make_shared<InstrTemp2<Instructions::MOV_A_AT_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xE7] = std::make_shared<InstrTemp2<Instructions::MOV_A_AT_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xE8] = std::make_shared<InstrTemp1<Instructions::MOV_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xE9] = std::make_shared<InstrTemp1<Instructions::MOV_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xEA] = std::make_shared<InstrTemp1<Instructions::MOV_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xEB] = std::make_shared<InstrTemp1<Instructions::MOV_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xEC] = std::make_shared<InstrTemp1<Instructions::MOV_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xED] = std::make_shared<InstrTemp1<Instructions::MOV_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xEE] = std::make_shared<InstrTemp1<Instructions::MOV_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xEF] = std::make_shared<InstrTemp1<Instructions::MOV_A_RN>>(*this, IP, flashMemory,xdata);
    decodeMap[0xF0] = std::make_shared<InstrTempl<Instructions::MOVX_A_AT_DPTR>>(*this, IP, flashMemory,xdata);
    decodeMap[0xF5] = std::make_shared<InstrTemp2<Instructions::MOV_DIRECT_A>>(*this, IP, flashMemory,xdata);
    decodeMap[0xF6] = std::make_shared<InstrTemp2<Instructions::MOV_AT_RN_A>>(*this, IP, flashMemory,xdata);
    decodeMap[0xF7] = std::make_shared<InstrTemp2<Instructions::MOV_AT_RN_A>>(*this, IP, flashMemory,xdata);
    decodeMap[0xF8] = std::make_shared<InstrTemp1<Instructions::MOV_RN_A>>(*this, IP, flashMemory,xdata);
    decodeMap[0xF9] = std::make_shared<InstrTemp1<Instructions::MOV_RN_A>>(*this, IP, flashMemory,xdata);
    decodeMap[0xFA] = std::make_shared<InstrTemp1<Instructions::MOV_RN_A>>(*this, IP, flashMemory,xdata);
    decodeMap[0xFB] = std::make_shared<InstrTemp1<Instructions::MOV_RN_A>>(*this, IP, flashMemory,xdata);
    decodeMap[0xFC] = std::make_shared<InstrTemp1<Instructions::MOV_RN_A>>(*this, IP, flashMemory,xdata);
    decodeMap[0xFD] = std::make_shared<InstrTemp1<Instructions::MOV_RN_A>>(*this, IP, flashMemory,xdata);
    decodeMap[0xFE] = std::make_shared<InstrTemp1<Instructions::MOV_RN_A>>(*this, IP, flashMemory,xdata);
    decodeMap[0xFF] = std::make_shared<InstrTemp1<Instructions::MOV_RN_A>>(*this, IP, flashMemory,xdata);
}

std::shared_ptr<Instruction> InstructionFactory::decode(uint8_t opcode) {
    return decodeMap[opcode];
}
