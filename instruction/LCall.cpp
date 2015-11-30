//
// Created by Paolo Achdjian on 11/30/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//
#include <iostream>
#include "LCall.h"
std::shared_ptr<Instruction> LCall::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        cycleCounter=6;
        IP++;
        uint16_t newAddress = flashMemory[IP]*256;
        IP++;
        newAddress += flashMemory[IP];
        IP++;
        uint16_t spAddress = SP.getValue();
        spAddress++;
        xdata[spAddress] = IP & 0xFF;
        spAddress++;
        xdata[spAddress] = (IP >> 8) & 0xFF;
        SP.setValue(spAddress);
        IP = newAddress;
        std::cout << "lcall to" << std::hex << (uint)newAddress << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}