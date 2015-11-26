//
// Created by Paolo Achdjian on 11/23/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#include "CPU.h"

CPU::CPU(FlashMemory &flashMemory) :flashMemory(flashMemory),instructionFactory(IP, flashMemory){
    IP=0;
}

void CPU::click() {
    auto data = flashMemory[IP];
}

void CPU::reset() {
    IP=0;

}
