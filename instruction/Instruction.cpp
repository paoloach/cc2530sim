//
// Created by Paolo Achdjian on 11/23/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//
#include <boost/log/trivial.hpp>
#include <sstream>
#include "Instruction.h"


template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::NOP>::cycle() {
    IP++;
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_A_DATA>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=2;
        IP++;
        uint8_t data = flashMemory[IP];
        IP++;
        xdata[Register::A]->setValue(data);
        BOOST_LOG_TRIVIAL(debug) << "move A <-- 0x"  <<(uint)data;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_DATA_DIRECT>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=3;
        IP++;
        uint8_t address = flashMemory[IP];
        IP++;
        uint8_t data = flashMemory[IP];
        IP++;
        xdata[address]->setValue(data);
        BOOST_LOG_TRIVIAL(debug)  << "move [" << xdata[address]->getName()<< "] <-- 0x" <<  (uint)data;
    }
    return instructionFactory.decode(flashMemory[IP]);
}






template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_A_DIRECT>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=2;
        IP++;
        uint8_t address = flashMemory[IP];
        uint8_t data = xdata[address]->getValue();
        xdata[Register::A]->setValue(data);
        IP++;
        BOOST_LOG_TRIVIAL(debug)  << "A <-- [" << xdata[address]->getName() << "]";
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_DIRECT_A>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        cycleCounter=2;
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        IP++;
        uint8_t address = flashMemory[IP];
        uint8_t data = xdata[Register::A]->getValue();
        xdata[address]->setValue(data);
        IP++;
        BOOST_LOG_TRIVIAL(debug)  << "[" <<xdata[address]->getName() << "] <-- A";
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::ANL_A_DATA>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=2;
        IP++;
        uint8_t data = flashMemory[IP];
        uint8_t REG_A = xdata[Register::A]->getValue();
        xdata[Register::A]->setValue(data & REG_A);
        IP++;
        BOOST_LOG_TRIVIAL(debug) << "A <-- A  & " << (uint)data;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::ORL_A_DATA>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=2;
        IP++;
        uint8_t data = flashMemory[IP];
        uint8_t REG_A = xdata[Register::A]->getValue();
        xdata[Register::A]->setValue(data | REG_A);
        IP++;
        BOOST_LOG_TRIVIAL(debug)<< "A <-- A  | "  << (uint)data;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::CLR_A>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=1;
        xdata[Register::A]->setValue(0);
        IP++;
        BOOST_LOG_TRIVIAL(debug) << "CLR A";
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_RN_DIRECT>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=4;
        uint16_t Raddress = registryUtil.getRAddress(flashMemory[IP]);
        IP++;
        uint8_t address = flashMemory[IP];
        uint8_t data = xdata[address]->getValue();
        xdata[Raddress]->setValue(data);
        IP++;
        BOOST_LOG_TRIVIAL(debug) << "R" << (Raddress & 0x7) << " <--  [" << xdata[address]->getName() << "]";
    }
    return instructionFactory.decode(flashMemory[IP]);
}



template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_RN_DATA>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=1;
        uint16_t address = registryUtil.getRAddress(flashMemory[IP]);
        IP++;
        uint8_t data = flashMemory[IP];
        xdata[address]->setValue(data);
        IP++;
        BOOST_LOG_TRIVIAL(debug) << "R" << (address & 0x7) << " <--  "  << (uint)data;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOV_DPTR_DATA>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=3;
        IP++;
        uint8_t  dphVal =flashMemory[IP];
        uint16_t DPH=registryUtil.getDPH();
        xdata[DPH]->setValue( dphVal);
        IP++;
        uint8_t  dplVal =flashMemory[IP];
        uint16_t DPL=registryUtil.getDPL();
        xdata[DPL]->setValue( dplVal);
        IP++;
        BOOST_LOG_TRIVIAL(debug) << "MOV DPTR," << (uint)dphVal << (uint)dplVal;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOVC_A_DPTR>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=3;
        IP++;
        uint16_t dph = xdata[registryUtil.getDPH()]->getValue();
        uint16_t dpl = xdata[registryUtil.getDPL()]->getValue();
        uint16_t dp = (dph << 8) | dpl;
        auto regA = xdata[Register::A];
        uint8_t val = flashMemory[dp+regA->getValue()];
        regA->setValue(val);
        BOOST_LOG_TRIVIAL(debug) <<  "MOVC A,@A+DPTR (dptr=" << dp << ", A = " << (int)regA->getValue() << ")";
    }
    return instructionFactory.decode(flashMemory[IP]);
}


template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::MOVX_A_AT_DPTR>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=3;
        IP++;
        uint16_t dph = xdata[registryUtil.getDPH()]->getValue();
        uint16_t dpl = xdata[registryUtil.getDPL()]->getValue();
        uint16_t dp = (dph << 8) | dpl;
        auto regA = xdata[Register::A];
        uint8_t val = xdata[dp]->getValue();
        regA->setValue(val);
        BOOST_LOG_TRIVIAL(debug) << "MOVX A,@DPTR (dptr=" <<  dp << ")";
    }
    return instructionFactory.decode(flashMemory[IP]);
}




template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::INC_DPTR>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=1;
        IP++;
        uint16_t dph = xdata[registryUtil.getDPH()]->getValue();
        uint16_t dpl = xdata[registryUtil.getDPL()]->getValue();
        uint16_t dp = (dph << 8) | dpl;
        dp++;
        xdata[registryUtil.getDPH()]->setValue( (dp & 0xFF00) >> 8);
        xdata[registryUtil.getDPL()]->setValue(dp & 0xFF);
        BOOST_LOG_TRIVIAL(debug) << "INC DPTR (dptr=" << dp << ")";
    }
    return instructionFactory.decode(flashMemory[IP]);
}


template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::PUSH>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=4;
        uint16_t spAddress = xdata[Register::SP]->getValue();
        spAddress++;
        IP++;
        uint8_t address = flashMemory[IP];
        auto mem = xdata[address];
        xdata[spAddress]->setValue( mem->getValue());
        xdata[Register::SP]->setValue(spAddress);
        IP++;

        BOOST_LOG_TRIVIAL(debug) << "push " << mem->getName();
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::POP>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=4;
        uint16_t spAddress = xdata[Register::SP]->getValue();
        IP++;
        uint8_t address = flashMemory[IP];
        auto mem = xdata[address];
        mem->setValue( xdata[spAddress]->getValue());
        spAddress--;
        xdata[Register::SP]->setValue(spAddress);
        IP++;

        BOOST_LOG_TRIVIAL(debug) << "pop " << mem->getName();
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::RL_A>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=1;
        uint16_t regA = xdata[Register::A]->getValue();
        regA = regA << 1;
        if (regA & 0x100){
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
    auto xAddress = xdata[bitAddress];
    xAddress->setBit(bit, false);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "CLR BIT " << bit << " of [" << xAddress->getName() << "]";
}

template<>
void InstrTemp1<Instructions::CLR_C>::execution() {
    IP++;
    auto statusWord = xdata[Register::PSW];
    statusWord->setBit(7,false);
    BOOST_LOG_TRIVIAL(debug) << "CLR C ";
}

