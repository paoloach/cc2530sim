//
// Created by Paolo Achdjian on 12/1/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#ifndef CC2530SIM_INSTRUCTIONS_H
#define CC2530SIM_INSTRUCTIONS_H

enum class Instructions {
    NOP=0,
    AJMP=1,
    LJMP=2,
    RR_A=0x03,
    INC_A=0x04,
    INC_ADDR=0x05,
    INC_AT_Rn=0x06,
    INC_RN=0x08,
    JBC=0x10,
    ACALL=0x11,
    LCALL=0x12,
    RRC_A=0x13,
    DEC_A=0x14,
    DEC_ADDR=0x15,
    DEC_AT_Rn=0x16,
    DEC_RN=0x18,
    JB=0x20,
    RET=0x22,
    RL_A=0x23,
    ADD_A_DATA=0x24,
    ADD_A_DIRECT=0x25,
    ADD_A_AT_RN=0x26,
    ADD_A_RN=0x28,
    JNB=0x30,
    RETI=0x32,
    RLC_A=0x33,
    ADDC_A_DATA=0x34,
    ADDC_A_DIRECT=0x35,
    ADDC_A_AT_RN=0x36,
    ADDC_A_RN=0x38,
    JC=0x40,
    ORL_AND_DIRECT_A=0x42,
    ORL_AND_DIRECT_DATA=0x43,
    ORL_AND_A_DATA=0x44,
    ORL_AND_A_DIRECT=0x45,
    ORL_AND_A_AT_R0=0x46,
    ORL_AND_A_RN=0x48,
    JNC=0x50,
    ANL_A_DATA=0x54,
    JZ=0x60,
    JNZ=0x70,
    ORL_C_BIT=0x72,
    JMP_A_DPTR=0x73,
    MOV_A_DATA=0x74,
    MOV_DATA_DIRECT=0x75,
    MOV_AT_R0_DATA=0x76,
    MOV_RN_DATA=0x78,
    SJMP=0x80,
    ANL_C_BIT=0x82,
    MOV_A_AT_A_PC=0x83,
    DIV_AB=0x84,
    MOV_DIRECT_DIRECT=0x85,
    MOV_DIRECT_AT_R=0x86,
    MOV_DIRECT_RN=0x88,
    MOV_DPTR_DATA=0x90,
    MOV_BIT_ADDR_C=0x92,
    MOVC_A_DPTR=0x93,
    SUBB_A_DATA=0x94,
    SUBB_A_DIRECT=0x95,
    SUBB_A_AT_RN=0x96,
    SUBB_A_RN=0x98,
    ORL_C_NOT_BIT=0xA0,
    INC_DPTR=0xA3,
    MOV_C_BIT_ADDR=0xA2,
    MUL_AB=0xA4,
    MOV_AT_R_DIRECT=0xA6,
    MOV_RN_DIRECT=0xA8,
    ANL_C_NOT_BIT=0xB0,
    CPL_BIT_ADDR=0xB2,
    CPL_C=0xB3,
    CJNE_A_DATA=0xB4,
    CJNE_A_DIRECT=0xB5,
    CJNE_AT_RN_DATA=0xB6,
    CJNE_RN_DATA=0xB8,
    PUSH=0xC0,
    CLR_BIT=0xC2,
    CLR_C=0xC3,
    SWAP_A=0xC4,
    XCH_A_DIRECT=0xC5,
    XCH_A_AT_RN=0xC6,
    XCH_A_RN=0xC8,
    POP=0xD0,
    SETB_BIT_ADDR=0xD2,
    SET_C=0xD3,
    DA=0xD4,
    DJNZ_RN=0xD8,
    MOVX_A_AT_DPTR=0xE0,
    MOVX_A_AT_R=0xE2,
    CLR_A=0xE4,
    MOV_A_DIRECT=0xE5,

    MOV_A_AT_RN=0xE6,
    MOV_A_RN=0xE8,

    MOVX_AT_DPTR_A=0xF0,
    MOVX_AT_R_A=0xF2,
    MOV_DIRECT_A=0xF5,
    MOV_AT_RN_A=0xF6,
    MOV_RN_A = 0xF8

};

#endif //CC2530SIM_INSTRUCTIONS_H
