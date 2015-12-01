//
// Created by Paolo Achdjian on 11/26/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "MovImmediateToDirect.h"
std::shared_ptr<Instruction> MovImmediateToDirect::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        cycleCounter=3;
        IP++;
        uint8_t address = flashMemory[IP];
        IP++;
        uint8_t data = flashMemory[IP];
        IP++;
        xdata[address].setValue(data);
        std::cout << "move in 0x" << std::setw(2) << std::setfill('0')  << std::hex << (uint)address << " <-- 0x" <<   std::setw(2) <<(uint)data << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}