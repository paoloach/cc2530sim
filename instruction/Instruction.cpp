//
// Created by Paolo Achdjian on 11/23/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#include <stdint.h>
#include "Instruction.h"
#include "InstructionFactory.h"
#include "Instructions.h"


template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::NOP>::cycle() {
    IP++;
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_DATA_DIRECT>::cycle() {
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

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::LJMP>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        cycleCounter=3;
        IP++;
        IP = flashMemory[IP]*256 + flashMemory[IP+1];

    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::LCALL>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        cycleCounter=6;
        IP++;
        uint16_t newAddress = flashMemory[IP]*256;
        IP++;
        newAddress += flashMemory[IP];
        IP++;
        uint16_t spAddress = xdata[Register::SP].getValue();
        spAddress++;
        xdata[spAddress] = IP & 0xFF;
        spAddress++;
        xdata[spAddress] = (IP >> 8) & 0xFF;
        xdata[Register::SP].setValue(spAddress);
        IP = newAddress;
        std::cout << "lcall to address 0x" << std::uppercase << std::setw(4) << std::setfill('0') << std::hex <<  (uint)newAddress << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_A_DIRECT>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        cycleCounter=2;
        IP++;
        uint8_t address = flashMemory[IP];
        uint8_t data = xdata[address].getValue();
        xdata[Register::A].setValue(data);
        IP++;
        std::cout << "move in A <-- [" << std::setfill('0')  << std::setw(2) << std::hex << (uint)address << "]" << std::endl;
    }
    return instructionFactory.decode(flashMemory[IP]);
}