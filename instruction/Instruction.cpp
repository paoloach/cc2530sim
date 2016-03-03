//
// Created by Paolo Achdjian on 11/23/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//
#include <boost/log/trivial.hpp>
#include <sstream>
#include "Instruction.h"


template<>
void InstrTemp1<Instructions::NOP>::execution() {
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "NOP";
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_A_DATA>::cycle() {
    if (cycleCounter > 0) {
        cycleCounter--;
    } else {
        std::cout << std::setfill('0') << std::setw(4) << IP << "  ";
        cycleCounter = 2;
        IP++;
        uint8_t data = flashMemory[IP];
        IP++;
        xdata[Register::A]->setValue(data);
        BOOST_LOG_TRIVIAL(debug) << "move A <-- 0x" << (uint) data;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
void InstrTemp3<Instructions::MOV_DATA_DIRECT>::execution() {
    IP++;
    uint8_t address = flashMemory[IP];
    IP++;
    uint8_t data = flashMemory[IP];
    IP++;
    xdata[address]->setValue(data);
    BOOST_LOG_TRIVIAL(debug) << "move [" << xdata[address]->getName() << "] <-- 0x" << (uint) data;
}


template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::ANL_A_DATA>::cycle() {
    if (cycleCounter > 0) {
        cycleCounter--;
    } else {
        std::cout << std::setfill('0') << std::setw(4) << IP << "  ";
        cycleCounter = 2;
        IP++;
        uint8_t data = flashMemory[IP];
        uint8_t REG_A = xdata[Register::A]->getValue();
        xdata[Register::A]->setValue(data & REG_A);
        IP++;
        BOOST_LOG_TRIVIAL(debug) << "A <-- A  & " << (uint) data;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::ORL_A_DATA>::cycle() {
    if (cycleCounter > 0) {
        cycleCounter--;
    } else {
        std::cout << std::setfill('0') << std::setw(4) << IP << "  ";
        cycleCounter = 2;
        IP++;
        uint8_t data = flashMemory[IP];
        uint8_t REG_A = xdata[Register::A]->getValue();
        xdata[Register::A]->setValue(data | REG_A);
        IP++;
        BOOST_LOG_TRIVIAL(debug) << "A <-- A  | " << (uint) data;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::CLR_A>::cycle() {
    if (cycleCounter > 0) {
        cycleCounter--;
    } else {
        std::cout << std::setfill('0') << std::setw(4) << IP << "  ";
        cycleCounter = 1;
        xdata[Register::A]->setValue(0);
        IP++;
        BOOST_LOG_TRIVIAL(debug) << "CLR A";
    }
    return instructionFactory.decode(flashMemory[IP]);
}



template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_RN_DATA>::cycle() {
    if (cycleCounter > 0) {
        cycleCounter--;
    } else {
        std::cout << std::setfill('0') << std::setw(4) << IP << "  ";
        cycleCounter = 1;
        uint16_t address = registryUtil.getRAddress(flashMemory[IP]);
        IP++;
        uint8_t data = flashMemory[IP];
        xdata[address]->setValue(data);
        IP++;
        BOOST_LOG_TRIVIAL(debug) << "MOV R" << (address & 0x7) << " <--  " << (uint) data;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_DPTR_DATA>::cycle() {
    if (cycleCounter > 0) {
        cycleCounter--;
    } else {
        std::cout << std::setfill('0') << std::setw(4) << IP << "  ";
        cycleCounter = 3;
        IP++;
        uint8_t dphVal = flashMemory[IP];
        uint16_t DPH = registryUtil.getDPH();
        xdata[DPH]->setValue(dphVal);
        IP++;
        uint8_t dplVal = flashMemory[IP];
        uint16_t DPL = registryUtil.getDPL();
        xdata[DPL]->setValue(dplVal);
        IP++;
        BOOST_LOG_TRIVIAL(debug) << "MOV DPTR," << (uint) dphVal << (uint) dplVal;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
void InstrTemp3<Instructions::MOVC_A_DPTR>::execution() {
    IP++;
    uint16_t dph = xdata[registryUtil.getDPH()]->getValue();
    uint16_t dpl = xdata[registryUtil.getDPL()]->getValue();
    uint16_t dp = (dph << 8) | dpl;
    auto regA = xdata[Register::A];
    int aValue = regA->getValue();
    uint8_t val = flashMemory[dp + aValue];
    regA->setValue(val);
    BOOST_LOG_TRIVIAL(debug) << "MOVC A(=" << val << ") ,@A+DPTR (dptr=" << dp << ", A = " << aValue << ")";
}


template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOVX_A_AT_DPTR>::cycle() {
    if (cycleCounter > 0) {
        cycleCounter--;
    } else {
        std::cout << std::setfill('0') << std::setw(4) << IP << "  ";
        cycleCounter = 3;
        IP++;
        uint16_t dph = xdata[registryUtil.getDPH()]->getValue();
        uint16_t dpl = xdata[registryUtil.getDPL()]->getValue();
        uint16_t dp = (dph << 8) | dpl;
        auto regA = xdata[Register::A];
        uint8_t val = xdata[dp]->getValue();
        regA->setValue(val);
        BOOST_LOG_TRIVIAL(debug) << "MOVX A,@DPTR (dptr=" << dp << ")";
    }
    return instructionFactory.decode(flashMemory[IP]);
}


template<>
void InstrTemp4<Instructions::PUSH>::execution() {
    uint16_t spAddress = xdata[Register::SP]->getValue();
    spAddress++;
    IP++;
    uint8_t address = flashMemory[IP];
    auto mem = xdata[address];
    xdata[spAddress]->setValue(mem->getValue());
    xdata[Register::SP]->setValue(spAddress);
    IP++;

    BOOST_LOG_TRIVIAL(debug) << "push " << mem->getName();
}

template<>
void InstrTemp3<Instructions::POP>::execution() {
    uint16_t spAddress = xdata[Register::SP]->getValue();
    IP++;
    uint8_t address = flashMemory[IP];
    auto mem = xdata[address];
    mem->setValue(xdata[spAddress]->getValue());
    spAddress--;
    xdata[Register::SP]->setValue(spAddress);
    IP++;

    BOOST_LOG_TRIVIAL(debug) << "pop " << mem->getName();
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::RL_A>::cycle() {
    if (cycleCounter > 0) {
        cycleCounter--;
    } else {
        std::cout << std::setfill('0') << std::setw(4) << IP << "  ";
        cycleCounter = 1;
        uint16_t regA = xdata[Register::A]->getValue();
        regA = regA << 1;
        if (regA & 0x100) {
            regA |= 1;
        }
        xdata[Register::A]->setValue(regA);
        IP++;
        BOOST_LOG_TRIVIAL(debug) << "RL A";
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
void InstrTemp3<Instructions::CLR_BIT>::execution() {
    IP++;
    auto xBitAddress = xdata[flashMemory[IP]];
    auto bitAddress = xBitAddress->getValue();
    auto bit = bitAddress & 0x07;
    auto address = registryUtil.getXAddressFromBitAddress(xBitAddress->getValue());
    auto xAddress = xdata[address];
    xAddress->setBit(bit, false);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "CLR BIT " << bit << " of [" << xAddress->getName() << "]";
}

template<>
void InstrTemp2<Instructions::MOV_C_BIT_ADDR>::execution() {
    IP++;
    auto xBitAddress = xdata[flashMemory[IP]];
    auto bitAddress = xBitAddress->getValue();
    auto bit = bitAddress & 0x07;
    auto address = registryUtil.getXAddressFromBitAddress(xBitAddress->getValue());
    auto xAddress = xdata[address];
    bool bitValue = xAddress->getBit(bit);
    xdata[Register::PSW]->setBit(7, bitValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "MOV C, bit " << bit << " of [" << xAddress->getName() << "]";
}

template<>
void InstrTemp1<Instructions::CLR_C>::execution() {
    IP++;
    auto statusWord = xdata[Register::PSW];
    statusWord->setBit(7, false);
    BOOST_LOG_TRIVIAL(debug) << "CLR C ";
}

