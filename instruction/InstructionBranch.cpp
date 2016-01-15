//
// Created by developer on 1/14/16.
//
#include <boost/log/trivial.hpp>
#include <stdint.h>
#include "Instruction.h"

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::LJMP>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        BOOST_LOG_TRIVIAL(debug) << IP <<"  ";
        cycleCounter=3;
        IP++;
        IP = flashMemory[IP]*256 + flashMemory[IP+1];
        BOOST_LOG_TRIVIAL(debug) << "LJMP (at " <<  (uint)IP << ")";
    }
    return instructionFactory.decode(flashMemory[IP]);
}


template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::JMP_A_DPTR>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        BOOST_LOG_TRIVIAL(debug) << IP <<"  ";
        cycleCounter=2;
        uint16_t dph = xdata[registryUtil.getDPH()]->getValue();
        uint16_t dpl = xdata[registryUtil.getDPL()]->getValue();
        uint16_t dp = (dph << 8) | dpl;
        auto regA = xdata[Register::A]->getValue();
        IP = dp + regA;
        BOOST_LOG_TRIVIAL(debug) << "JMP @A+DTR (at " << (uint)IP << ")";
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::LCALL>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=6;
        IP++;
        uint16_t newAddress = flashMemory[IP]*256;
        IP++;
        newAddress += flashMemory[IP];
        IP++;
        uint32_t oldAddress = IP;
        uint16_t spAddress = xdata[Register::SP]->getValue();
        spAddress++;
        xdata[spAddress]->setValue( IP & 0xFF);
        spAddress++;
        xdata[spAddress]->setValue((IP >> 8) & 0xFF);
        xdata[Register::SP]->setValue(spAddress);
        IP = newAddress;
        BOOST_LOG_TRIVIAL(debug) << "LCALL to address "  <<  (uint)newAddress << " (old address was " <<  oldAddress << ")";
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::RET>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=4;
        uint16_t spAddress = xdata[Register::SP]->getValue();
        uint32_t hiIP = xdata[spAddress]->getValue();
        spAddress--;
        uint32_t lowIP = xdata[spAddress]->getValue();
        spAddress--;
        xdata[Register::SP]->setValue(spAddress);

        IP = (hiIP << 8)  | lowIP;

        BOOST_LOG_TRIVIAL(debug) << "RET to address " <<  (uint)IP;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::CJNE_RN_DATA>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=4;
        uint16_t rAddress = registryUtil.getRAddress(flashMemory[IP]);
        IP++;
        uint8_t data = flashMemory[IP];
        IP++;
        int8_t relAddr = flashMemory[IP];
        IP++;
        if (xdata[rAddress]->getValue() != data){
            IP += relAddr;
        }
        if (xdata[rAddress]->getValue() < data){
            xdata[Register::PSW]->setBit(7,true);
        } else {
            xdata[Register::PSW]->setBit(7,false);
        }

        BOOST_LOG_TRIVIAL(debug) << "CJNE R" << (rAddress & 0x7) <<", " << (uint)data << ", " <<  (int)relAddr;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::DJNZ_RN>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=3;
        uint16_t regAddress = registryUtil.getRAddress(flashMemory[IP]);
        IP++;
        int8_t relAddr = flashMemory[IP];
        IP++;
        uint8_t rn= xdata[regAddress]->getValue();
        rn--;
        xdata[regAddress]->setValue(rn);
        if (rn != 0){
            IP += relAddr;
        }

        BOOST_LOG_TRIVIAL(debug) << "DJNZ R" << (regAddress & 0x7) << "," << (int)relAddr;
    }
    return instructionFactory.decode(flashMemory[IP]);
}

template<>
std::shared_ptr<Instruction> InstrTempl<Instructions::SJMP>::cycle() {
    if (cycleCounter>0){
        cycleCounter--;
    } else {
        std::cout  << std::setfill('0')  << std::setw(4) << IP <<"  ";
        cycleCounter=3;
        IP++;
        int8_t relAddr = flashMemory[IP];
        IP++;
        IP += relAddr;

        BOOST_LOG_TRIVIAL(debug) << "SJMP AT " << (uint)IP;
    }
    return instructionFactory.decode(flashMemory[IP]);
}


template<>
void InstrTemp4<Instructions::JBC>::execution() {
    IP++;
    auto bitAddress = flashMemory[IP];
    auto bit = bitAddress & 0x07;
    auto address = registryUtil.getXAddressFromBitAddress(bitAddress);
    auto xAddress = xdata[bitAddress];
    IP++;
    int8_t relAddr = flashMemory[IP];
    IP++;
    auto destIP = IP+relAddr;
    if (xAddress->getBit(bit)){
        xAddress->setBit(bit,false);
        IP = destIP;
    }
    BOOST_LOG_TRIVIAL(debug) << "JBC [" << xAddress->getName() <<"], bit " << bit << " " << destIP;
}
