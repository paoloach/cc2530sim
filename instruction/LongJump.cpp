//
// Created by Paolo Achdjian on 11/24/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#include "LongJump.h"
std::shared_ptr<Instruction> LongJump::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        cycleCounter=3;
        IP++;
        IP = flashMemory[IP]*256 + flashMemory[IP+1];

    }
    return instructionFactory.decode(flashMemory[IP]);
}