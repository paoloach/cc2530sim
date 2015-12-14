//
// Created by Paolo Achdjian on 12/1/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#ifndef CC2530SIM_REGISTERS_H
#define CC2530SIM_REGISTERS_H

enum class Register {
    SP=0x81,
    DPL0=0x82,
    DPH0=0x83,
    DPL1=0x84,
    DPH1=0x85,
    DPS=0x92,

    PSW=0xD0,
    A=0xE0,
    B=0xF0,


};

#endif //CC2530SIM_REGISTERS_H
