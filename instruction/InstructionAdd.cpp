//
// Created by developer on 12/21/15.
//
#include <stdint.h>
#include <sstream>
#include "Instruction.h"
#include <boost/log/trivial.hpp>

template<>
void InstrTemp2<Instructions::ADD_A_DATA>::execution() {
    IP++;
    auto data = flashMemory[IP];
    auto REG_A = xdata.A->getValue();
    int16_t newValue = data + REG_A.getValue();
    bool carry = newValue & 0x100;
    bool ov;
    auto statusWord = xdata[Register::PSW];
    statusWord->setBit(7, carry);
    statusWord->setBit(2, ov);
    xdata[Register::A]->setValue(newValue);
    IP++;
    if (data >= 0){
        BOOST_LOG_TRIVIAL(debug) << "A(=" << (newValue & 0xFF) << ") <-- A  + " << (((uint) data) & 0xFF);
    } else {
        data = -data;
        BOOST_LOG_TRIVIAL(debug) << "A(=" << (newValue & 0xFF) << ") <-- A  -  " << (((uint) data) & 0xFF);
    }
}


template<>
void InstrTemp1<Instructions::ADD_A_RN>::execution() {
    uint16_t Raddress = registryUtil.getRAddress(flashMemory[IP]);
    IP++;
    auto rn = xdata[Raddress];
    auto REG_A = xdata.A->getValue();
    int16_t newValue = (rn->getValue() + REG_A.getValue()).getValue();
    bool carry = newValue & 0x100;
    bool ov;
    xdata.status->setBit(7, carry);
    xdata.status->setBit(2, ov);
    xdata.A->setValue(newValue);
    BOOST_LOG_TRIVIAL(debug) << "A <-- A  + R" << Raddress;
}

template<>
void InstrTemp2<Instructions::ADD_A_AT_RN>::execution() {
    uint16_t Raddress = registryUtil.getRAddress(flashMemory[IP] & 0x01);
    IP++;
    auto rn = xdata[Raddress];
    auto rVal = rn->getValue();
    auto xMem = xdata[rVal];
    auto REG_A = xdata.A->getValue();
    int16_t newValue = (xMem->getValue() + REG_A).getValue();
    bool carry = newValue & 0x100;
    bool ov;
    xdata.status->setBit(7, carry);
    xdata.status->setBit(2, ov);
    xdata.A->setValue(newValue);
    BOOST_LOG_TRIVIAL(debug) << "A <-- A  +@R" << Raddress << "([" << xMem->getName() << "])";
}

template<>
void InstrTemp2<Instructions::ADD_A_DIRECT>::execution() {
    IP++;
    auto address = xdata[flashMemory[IP]];
    auto data = address->getValue();
    auto REG_A = xdata.A->getValue();
    int16_t newValue = (data + REG_A.getValue()).getValue();
    bool carry = newValue & 0x100;
    bool ov;
    xdata.status->setBit(7, carry);
    xdata.status->setBit(2, ov);
    xdata.A->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "A <-- A  + [" << address->getName() << "] + carry";
}


template<>
void InstrTemp2<Instructions::ADDC_A_DATA>::execution() {
    IP++;
    auto data = flashMemory[IP];
    auto REG_A = xdata.A->getValue();
    bool carry = xdata.status->getBit(7);
    int16_t newValue = data + REG_A.getValue() + carry;
    carry = newValue & 0x100;
    bool ov;
    xdata.status->setBit(7, carry);
    xdata.status->setBit(2, ov);
    xdata.A->setValue(newValue);
    IP++;
    std::stringstream log;
    log << "A(=" << newValue << ") <-- A + carry ";
    if (data >= 0) {
        log << " + ";
    } else {
        log << " - ";
        data = - data;
    }
     log << std::setfill('0') << std::setw(2) << std::hex << (uint)data;
    BOOST_LOG_TRIVIAL(debug) << log.str();
}


template<>
void InstrTemp1<Instructions::ADDC_A_RN>::execution() {
    uint16_t Raddress = registryUtil.getRAddress(flashMemory[IP]);
    IP++;
    auto rn = xdata[Raddress];
    auto REG_A = xdata.A->getValue();
    bool carry = xdata.status->getBit(7);
    int16_t newValue = (rn->getValue() + REG_A).getValue() + carry ? 1 : 0;
    carry = newValue & 0x100;
    bool ov;
    xdata.status->setBit(7, carry);
    xdata.status->setBit(2, ov);
    xdata.A->setValue(newValue);
    BOOST_LOG_TRIVIAL(debug) << "A <-- A  + R" << Raddress << " + carry";
}

template<>
void InstrTemp2<Instructions::ADDC_A_AT_RN>::execution() {
    uint16_t Raddress = registryUtil.getRAddress(flashMemory[IP] & 0x01);
    IP++;
    auto rn = xdata[Raddress];
    auto rVal = rn->getValue();
    auto xMem = xdata[rVal];
    bool carry = xdata.status->getBit(7);
    auto REG_A = xdata.A->getValue();
    int16_t newValue = (xMem->getValue() + REG_A+ carry).getValue();
    carry = newValue & 0x100;
    bool ov;
    xdata.status->setBit(7, carry);
    xdata.status->setBit(2, ov);
    xdata.A->setValue(newValue);
    BOOST_LOG_TRIVIAL(debug) << "A <-- A  +@R +carry" << Raddress << "([" << xMem->getName() << "])";
}

template<>
void InstrTemp2<Instructions::ADDC_A_DIRECT>::execution() {
    IP++;
    auto address = xdata[flashMemory[IP]];
    auto data = address->getValue();
    bool carry = xdata.status->getBit(7);
    auto REG_A = xdata.A->getValue();
    int16_t newValue = (data + REG_A).getValue()+ carry;
    carry = newValue & 0x100;
    bool ov;
    xdata.status->setBit(7, carry);
    xdata.status->setBit(2, ov);
    xdata.A->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "A <-- A  + [" << address->getName() << "] + carry";
}