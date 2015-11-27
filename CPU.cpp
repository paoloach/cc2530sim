//
// Created by Paolo Achdjian on 11/23/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#include "CPU.h"

CPU::CPU(FlashMemory &flashMemory) :flashMemory(flashMemory),instructionFactory(IP, flashMemory,xdata){
    IP=0;
    xdata.resize(32*1024);
}

void CPU::click() {
    currentInstruct = currentInstruct->cycle();
}

void CPU::reset() {
    IP=0;
    currentInstruct = instructionFactory.decode(flashMemory[IP]);
}
