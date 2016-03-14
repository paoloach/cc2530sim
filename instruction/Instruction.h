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

#include "InstructionFactory.h"
#include "../InstructionPointer.h"
#include "../Data8.h"

class InstructionFactory;
class FlashMemory;
class XData;

class Instruction {
public:
    Instruction(InstructionFactory &instructionFactory, InstructionPointer &IP, FlashMemory &flashMemory, XData &xdata)
    : instructionFactory(
            instructionFactory), IP(IP), flashMemory(flashMemory), xdata(xdata), cycleCounter(1),registryUtil(xdata) { }

    Instruction(InstructionFactory &instructionFactory, InstructionPointer &IP, FlashMemory &flashMemory, XData &xdata,int cycleCounter)
            : instructionFactory(
            instructionFactory), IP(IP), flashMemory(flashMemory), xdata(xdata), cycleCounter(cycleCounter),registryUtil(xdata) { }

    virtual ~Instruction() = default;

    virtual std::shared_ptr<Instruction> cycle() = 0;
protected:
    InstructionFactory &instructionFactory;
    FlashMemory &flashMemory;
    InstructionPointer &IP;
    XData &xdata;
    RegistryUtil registryUtil;
    int cycleCounter;
};

template <Instructions E>
class InstrTempl: public Instruction{
public:
    InstrTempl(InstructionFactory &instructionFactory, InstructionPointer &IP, FlashMemory &flashMemory, XData &xdata):
            Instruction(instructionFactory, IP, flashMemory, xdata){}
    InstrTempl(InstructionFactory &instructionFactory, InstructionPointer &IP, FlashMemory &flashMemory, XData &xdata, int cycleCount):
            Instruction(instructionFactory, IP, flashMemory, xdata,cycleCount){}

    std::shared_ptr<Instruction> cycle()  override{
        auto OP = flashMemory[IP];
        std::cout << "unknown op 0x" <<  std::setw(2) << std::setfill('0') << std::hex << (int)OP << " at " << IP << std::endl;
        exit(-1);
    }
};

template <Instructions E>
class InstrTemp6: public Instruction{
public:
    InstrTemp6(InstructionFactory &instructionFactory, InstructionPointer &IP, FlashMemory &flashMemory, XData &xdata):
            Instruction(instructionFactory, IP, flashMemory, xdata,6){}

    std::shared_ptr<Instruction> cycle() override {
        if (cycleCounter>0){
            cycleCounter--;
        } else {
            cycleCounter=6;
            uint opcode = flashMemory[IP];
            uint opcode1 = flashMemory[IP+1];
            std::cout  << IP <<"  " << std::hex << opcode << " " << opcode1  << " [" << xdata[4]->getValue() << "] ";;
            execution();
        }
        return instructionFactory.decode(flashMemory[IP]);
    }

    void execution() {
        auto OP = flashMemory[IP];
        std::cout << "unknown op 0x" <<  std::setw(2) << std::setfill('0') << std::hex << (int)OP << " at " <<IP << std::endl;
        exit(-1);
    }
};

template <Instructions E>
class InstrTemp5: public Instruction{
public:
    InstrTemp5(InstructionFactory &instructionFactory, InstructionPointer &IP, FlashMemory &flashMemory, XData &xdata):
            Instruction(instructionFactory, IP, flashMemory, xdata,5){}

    std::shared_ptr<Instruction> cycle() override {
        if (cycleCounter>0){
            cycleCounter--;
        } else {
            cycleCounter=5;
            uint opcode = flashMemory[IP];
            uint opcode1 = flashMemory[IP+1];
            std::cout  << IP <<"  " << std::hex << opcode << " " << opcode1  << " [" << xdata[4]->getValue() << "] ";;
            execution();
        }
        return instructionFactory.decode(flashMemory[IP]);
    }

    void execution() {
        auto OP = flashMemory[IP];
        std::cout << "unknown op 0x" <<  std::setw(2) << std::setfill('0') << std::hex << (int)OP << " at " <<IP << std::endl;
        exit(-1);
    }
};

template <Instructions E>
class InstrTemp4: public Instruction{
public:
    InstrTemp4(InstructionFactory &instructionFactory, InstructionPointer &IP, FlashMemory &flashMemory, XData &xdata):
            Instruction(instructionFactory, IP, flashMemory, xdata,4){}

    std::shared_ptr<Instruction> cycle() override {
        if (cycleCounter>0){
            cycleCounter--;
        } else {
            cycleCounter=4;
            uint opcode = flashMemory[IP];
            uint opcode1 = flashMemory[IP+1];
            std::cout  << IP <<"  " << std::hex << opcode << " " << opcode1  << " [" << xdata[4]->getValue() << "] ";;
            execution();
        }
        return instructionFactory.decode(flashMemory[IP]);
    }

    void execution() {
        auto OP = flashMemory[IP];
        std::cout << "unknown op 0x" <<  std::setw(2) << std::setfill('0') << std::hex << (int)OP << " at " <<IP << std::endl;
        exit(-1);
    }
};

template <Instructions E>
class InstrTemp3: public Instruction{
public:
    InstrTemp3(InstructionFactory &instructionFactory, InstructionPointer &IP, FlashMemory &flashMemory, XData &xdata):
            Instruction(instructionFactory, IP, flashMemory, xdata,3){}

    std::shared_ptr<Instruction> cycle() override {
        if (cycleCounter>0){
            cycleCounter--;
        } else {
            cycleCounter=3;
            uint opcode = flashMemory[IP];
            uint opcode1 = flashMemory[IP+1];
            std::cout  << IP <<"  " << std::hex << opcode << " " << opcode1  << " [" <<  xdata[4]->getValue() << "] ";;
            execution();
        }
        return instructionFactory.decode(flashMemory[IP]);
    }

    void execution() {
        auto OP = flashMemory[IP];
        std::cout << "unknown op 0x" <<  std::setw(2) << std::setfill('0') << std::hex << (int)OP << " at " << IP << std::endl;
        exit(-1);
    }
};

template <Instructions E>
class InstrTemp2: public Instruction{
public:
    InstrTemp2(InstructionFactory &instructionFactory, InstructionPointer &IP, FlashMemory &flashMemory, XData &xdata):
            Instruction(instructionFactory, IP, flashMemory, xdata,2){}

    std::shared_ptr<Instruction> cycle() override {
        if (cycleCounter>0){
            cycleCounter--;
        } else {
            cycleCounter=2;
            uint opcode = flashMemory[IP];
            uint opcode1 = flashMemory[IP+1];
            std::cout  << IP <<"  " << std::hex << opcode << " " << opcode1  << " [" << xdata[4]->getValue() << "] ";;
            execution();
        }
        return instructionFactory.decode(flashMemory[IP]);
    }

    void execution() {
        auto OP = flashMemory[IP];
        std::cout << "unknown op 0x" <<  std::setw(2) << std::setfill('0') << std::hex << (int)OP << " at " << IP << std::endl;
        exit(-1);
    }
};

template <Instructions E>
class InstrTemp1: public Instruction{
public:
    InstrTemp1(InstructionFactory &instructionFactory, InstructionPointer &IP, FlashMemory &flashMemory, XData &xdata):
            Instruction(instructionFactory, IP, flashMemory, xdata,1){}

    std::shared_ptr<Instruction> cycle() override {
        if (cycleCounter>0){
            cycleCounter--;
        } else {
            cycleCounter=1;
            uint opcode = flashMemory[IP];
            std::cout  << IP <<"  " << std::hex << opcode << " " << " [" << xdata[4]->getValue() << "] ";
            execution();
        }
        return instructionFactory.decode(flashMemory[IP]);
    }

    void execution() {
        auto OP = flashMemory[IP];
        std::cout << "unknown op 0x" <<  std::setw(2) << std::setfill('0') << std::hex << (int)OP << " at " << IP << std::endl;
        exit(-1);
    }
};


#endif //CC2530SIM_INSTRUCTION_H
