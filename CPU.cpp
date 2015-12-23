//
// Created by Paolo Achdjian on 11/23/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#include "CPU.h"
#include "instruction/Instruction.h"

CPU::CPU(FlashMemory &flashMemory) :flashMemory(flashMemory),instructionFactory(IP, flashMemory,xdata){
    IP=0;
}

void CPU::click() {
    currentInstruct = currentInstruct->cycle();
}

void CPU::reset() {
    IP=0;
    currentInstruct = instructionFactory.decode(flashMemory[IP]);
}
