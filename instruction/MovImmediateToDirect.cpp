//
// Created by Paolo Achdjian on 11/26/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#include <iostream>
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
        std::cout << "move in " << std::hex << (uint)address << " <-- " << (uint)data << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}