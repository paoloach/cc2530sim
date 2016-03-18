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
void InstrTemp3<Instructions::SETB_BIT_ADDR>::execution() {
    IP++;
    auto xBitAddress = xdata[flashMemory[IP]];
    auto bitAddress = xBitAddress->getValue();
    auto bit = bitAddress & 0x07;
    auto address = registryUtil.getXAddressFromBitAddress(xBitAddress->getValue());
    auto xAddress = xdata[address];
    xAddress->setBit(bit.getValue(), true);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "SET BIT " << bit << " of [" << xAddress->getName() << "]";
}


template<>
void InstrTemp1<Instructions::CLR_C>::execution() {
    IP++;
    auto statusWord = xdata[Register::PSW];
    statusWord->setBit(7, false);
    BOOST_LOG_TRIVIAL(debug) << "CLR C ";
}

template<>
void InstrTemp1<Instructions::SET_C>::execution() {
    IP++;
    auto statusWord = xdata[Register::PSW];
    statusWord->setBit(7, true);
    BOOST_LOG_TRIVIAL(debug) << "SETB C ";
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

template<>
void InstrTemp5<Instructions::DIV_AB>::execution() {
    IP++;
    auto ris = xdata.A->getValue() / xdata.B->getValue();
    auto remainder = xdata.A->getValue() % xdata.B->getValue();
    xdata.A->setValue(ris);
    xdata.B->setValue(remainder);
    xdata.status->setBit(7, false);
    xdata.status->setBit(2, false);
    BOOST_LOG_TRIVIAL(debug) << "DIV  AB";
}

template<>
void InstrTemp5<Instructions::MUL_AB>::execution() {
    IP++;
    uint16_t ris = (uint16_t) (xdata.A->getValue().getValue()) * xdata.B->getValue().getValue();
    uint8_t hiByte = ris >> 8;
    xdata.A->setValue(Data8(ris));
    xdata.B->setValue(Data8(hiByte));
    xdata.status->setBit(2, hiByte > 0);
    xdata.status->setBit(7, false);
    BOOST_LOG_TRIVIAL(debug) << "MUL  AB";
}

template<>
void InstrTemp3<Instructions::CPL_BIT_ADDR>::execution() {
    IP++;
    auto xBitAddress = flashMemory[IP];
    auto bit = xBitAddress & 0x07;
    auto address = registryUtil.getXAddressFromBitAddress(Data8(xBitAddress));
    auto xAddress = xdata[address];
    xAddress->setBit(bit, !xAddress->getBit(bit));
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "CPL BIT " << bit << " of [" << xAddress->getName() << "]";
}

template<>
void InstrTemp3<Instructions::CPL_C>::execution() {
    IP++;
    xdata.status->setBit(7, !xdata.status->getBit(7));
    BOOST_LOG_TRIVIAL(debug) << "CPL C";
}

template<>
void InstrTemp1<Instructions::SWAP_A>::execution() {
    IP++;
    uint8_t a = xdata.A->getValue().getValue();
    uint8_t b = (a & 0x0F) << 4;
    uint8_t c = (a & 0xF0) >> 4;
    xdata.A->setValue(Data8(b | c));

    BOOST_LOG_TRIVIAL(debug) << "SWAP A(" << xdata.A->getValue() << ")";
}

template<>
void InstrTemp1<Instructions::DA>::execution() {
    IP++;
    uint8_t a = xdata.A->getValue().getValue();
    uint8_t b = (a & 0x0F);
    uint8_t c = (a & 0xF0) >> 4;
    if (b > 9 || xdata.status->getBit(6)){
        b+=6;
        if (b > 0xF){
            xdata.status->setBit(7,true);
            b &= 0xF;
        }
    }
    if (c > 9 || xdata.status->getBit(7)){
        c+=6;
        if (c > 0xF){
            xdata.status->setBit(7,true);
            c &= 0xF;
        }
    }
    xdata.A->setValue(Data8(b | (c << 4)));

    BOOST_LOG_TRIVIAL(debug) << "DA(" << xdata.A->getValue() << ")";
}