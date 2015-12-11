//
// Created by Paolo Achdjian on 11/23/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#ifndef CC2530SIM_INSTRUCTION_H
#define CC2530SIM_INSTRUCTION_H


#include <memory>
#include "Instructions.h"
#include "../FlashMemory.h"
#include "../Registers.h"
#include "RegistryUtil.h"
#include <iostream>
#include <iomanip>

class InstructionFactory;
class FlashMemory;
class XData;

class Instruction {
public:
    Instruction(InstructionFactory &instructionFactory, uint32_t &IP, FlashMemory &flashMemory, XData &xdata)
    : instructionFactory(
            instructionFactory), IP(IP), flashMemory(flashMemory), xdata(xdata), cycleCounter(1),registryUtil(xdata) { }

    Instruction(InstructionFactory &instructionFactory, uint32_t &IP, FlashMemory &flashMemory, XData &xdata,int cycleCounter)
            : instructionFactory(
            instructionFactory), IP(IP), flashMemory(flashMemory), xdata(xdata), cycleCounter(cycleCounter),registryUtil(xdata) { }

    virtual ~Instruction() = default;

    virtual std::shared_ptr<Instruction> cycle() = 0;
protected:
    InstructionFactory &instructionFactory;
    FlashMemory &flashMemory;
    uint32_t &IP;
    XData &xdata;
    RegistryUtil registryUtil;
    int cycleCounter;
};

template <Instructions E>
class InstrTempl: public Instruction{
public:
    InstrTempl(InstructionFactory &instructionFactory, uint32_t &IP, FlashMemory &flashMemory, XData &xdata):
            Instruction(instructionFactory, IP, flashMemory, xdata){}
    InstrTempl(InstructionFactory &instructionFactory, uint32_t &IP, FlashMemory &flashMemory, XData &xdata, int cycleCount):
            Instruction(instructionFactory, IP, flashMemory, xdata,cycleCount){}

    std::shared_ptr<Instruction> cycle() {
        auto OP = flashMemory[IP];
        std::cout << "unknown op 0x" <<  std::setw(2) << std::setfill('0') << std::hex << (int)OP << " at 0x" <<std::setw(4) << (int)IP << std::endl;
        exit(-1);
    }
};


#endif //CC2530SIM_INSTRUCTION_H
