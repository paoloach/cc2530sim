//
// Created by Paolo Achdjian on 11/23/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//
#include <boost/log/trivial.hpp>
#include <sstream>
#include "../Data8.h"
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
    auto dph = xdata[registryUtil.getDPH()]->getValue();
    auto dpl = xdata[registryUtil.getDPL()]->getValue();
    uint16_t dp = ((uint16_t) dph.getValue() << 8) | dpl.getValue();
    auto aValue = xdata.A->getValue();
    uint8_t val = flashMemory[dp + aValue.getSignedValue()];
    xdata.A->setValue(val);
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
        auto dph = xdata[registryUtil.getDPH()]->getValue();
        auto dpl = xdata[registryUtil.getDPL()]->getValue();
        uint16_t dp = (((uint16_t) (dph.getValue())) << 8) | dpl.getValue();
        auto val = xdata[dp]->getValue();
        xdata.A->setValue(val);
        BOOST_LOG_TRIVIAL(debug) << "MOVX A,@DPTR (dptr=" << dp << ")";
    }
    return instructionFactory.decode(flashMemory[IP]);
}


template<>
void InstrTemp4<Instructions::PUSH>::execution() {
    uint16_t spAddress = xdata[Register::SP]->getValue().getValue();
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
    uint16_t spAddress = xdata[Register::SP]->getValue().getValue();
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
void InstrTemp3<Instructions::CLR_BIT>::execution() {
    IP++;
    auto xBitAddress = xdata[flashMemory[IP]];
    auto bitAddress = xBitAddress->getValue();
    auto bit = bitAddress & 0x07;
    auto address = registryUtil.getXAddressFromBitAddress(xBitAddress->getValue());
    auto xAddress = xdata[address];
    xAddress->setBit(bit.getValue(), false);
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
    bool bitValue = xAddress->getBit(bit.getValue());
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

template<>
void InstrTemp1<Instructions::RR_A>::execution() {
    IP++;
    auto reg_a = xdata[Register::A];
    auto aRR = reg_a->getValue() >> 1;
    aRR &= 0x7F;
    reg_a->setValue(aRR);
    BOOST_LOG_TRIVIAL(debug) << "RR A";
}

template<>
void InstrTemp1<Instructions::RRC_A>::execution() {
    IP++;
    auto reg_a = xdata[Register::A];
    auto aRR = reg_a->getValue() >> 1;
    auto statusWord = xdata[Register::PSW]->getValue();
    if (statusWord.getBit(7)) {
        aRR |= 0x80;
    } else {
        aRR &= 0x7F;
    }
    reg_a->setValue(aRR);
    BOOST_LOG_TRIVIAL(debug) << "RR A";
}

template<>
void InstrTemp1<Instructions::RL_A>::execution() {
    auto A = xdata[Register::A];
    uint16_t regA = A->getValue().getValue();
    regA = regA << 1;
    if (regA & 0x100) {
        regA |= 1;
    }
    A->setValue(regA);
    IP++;
    auto a = A->getValue();
    BOOST_LOG_TRIVIAL(debug) << "RL A(" << a << ")";
}


template<>
void InstrTemp1<Instructions::RLC_A>::execution() {
    auto statusWord = xdata[Register::PSW];
    auto A = xdata[Register::A];
    uint16_t regA = A->getValue().getValue();
    regA = regA << 1;
    if (statusWord->getBit(7)) {
        regA |= 1;
    }
    if (regA & 0x100) {
        statusWord->setBit(7, true);
    }
    A->setValue(regA);
    IP++;
    auto a = A->getValue();
    BOOST_LOG_TRIVIAL(debug) << "RL A(" << a << ")";
}
