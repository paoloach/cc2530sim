//
// Created by Paolo Achdjian on 12/1/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#ifndef CC2530SIM_INSTRUCTIONS_H
#define CC2530SIM_INSTRUCTIONS_H

enum class Instructions {
    NOP=0,
    AJMP,
    LJMP=2,
    RR_A,
    INC_A,
    INC_ADDR,
    INC_AT_R0,
    INC_AT_R1,
    INC_RX,
    JBC=0x10,
    ACALL=0x11,
    LCALL=0x12,
    RET=0x22,
    ORL_DIRECT_A=0x42,
    ORL_DIRECT_DATA=0x43,
    ORL_A_DATA=0x44,
    ORL_A_DIRECT=0x45,
    ORL_A_AT_R0=0x46,
    ORL_A_AT_R1=0x47,
    ORL_A_R1=0x48,
    ANL_A_DATA=0x54,
    JMP_A_DPTR=0x73,
    MOV_A_DATA=0x74,
    MOV_DATA_DIRECT=0x75,
    MOV_RN_DATA=0x78,
    SJMP=0x80,
    MOV_DIRECT_RN=0x88,
    MOV_DPTR_DATA=0x90,
    MOVC_A_DPTR=0x93,
    CJNE_RN_DATA=0xB8,
    INC_DPTR=0xA3,
    MOV_RN_DIRECT=0xA8,
    PUSH=0xC0,
    DJNZ_RN=0xD8,
    CLR_A=0xE4,
    MOV_A_DIRECT=0xE5,
    MOVX_A_AT_DPTR=0xF0,
    MOV_DIRECT_A=0xF5

};

#endif //CC2530SIM_INSTRUCTIONS_H
