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
    MOV_DATA_DIRECT=0x75,
    MOV_A_DIRECT=0xE5

};

#endif //CC2530SIM_INSTRUCTIONS_H
