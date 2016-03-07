//
// Created by developer on 1/8/16.
//
#include <boost/log/trivial.hpp>
#include <sstream>
#include <stdint.h>
#include "Instruction.h"

template<>
void InstrTemp2<Instructions::SUBB_A_DATA>::execution() {
    IP++;
    auto statusWord = xdata[Register::PSW];
    auto data = flashMemory[IP];
    auto REG_A = xdata[Register::A]->getValue();
    bool carry = statusWord->getBit(7);
    int16_t newValue = REG_A.getValue() + carry -data;
    carry = newValue & 0x100;
    bool ov;
    statusWord->setBit(7, carry);
    statusWord->setBit(2, ov);
    xdata[Register::A]->setValue(newValue);
    IP++;
    std::stringstream ss;
    ss<< "A(=" << newValue << ") <-- A - C ";
    if (data >= 0) {
        ss << " - ";
    } else {
        ss << " + ";
        data = -data;
    }
    ss << std::setfill('0') << std::setw(2) << std::hex << (uint) data << " + carry" << std::endl;
    BOOST_LOG_TRIVIAL(debug) << ss.str();
}

template<>
void InstrTemp1<Instructions::SUBB_A_RN>::execution() {
    uint16_t Raddress = registryUtil.getRAddress(flashMemory[IP]);
    IP++;
    auto rn = xdata[Raddress];
    auto statusWord = xdata[Register::PSW];
    auto REG_A = xdata[Register::A]->getValue();
    bool carry = statusWord->getBit(7);
    int16_t newValue = (REG_A  - rn->getValue()).getValue()- carry;
    carry = newValue & 0x100;
    bool ov;
    statusWord->setBit(7, carry);
    statusWord->setBit(2, ov);
    xdata[Register::A]->setValue(newValue);
    BOOST_LOG_TRIVIAL(debug) << "A(=" << newValue <<") <-- A - C - R" + Raddress;
}

template<>
void InstrTemp2<Instructions::SUBB_A_AT_RN>::execution() {
    uint16_t Raddress = registryUtil.getRAddress(flashMemory[IP] & 0x01);
    IP++;
    auto rn = xdata[Raddress];
    auto rVal = rn->getValue();
    auto xMem = xdata[rVal];
    auto statusWord = xdata[Register::PSW];
    bool carry = statusWord->getBit(7);
    auto REG_A = xdata[Register::A]->getValue();
    int16_t newValue = (REG_A - xMem->getValue()).getValue()- carry;
    carry = newValue & 0x100;
    bool ov;
    statusWord->setBit(7, carry);
    statusWord->setBit(2, ov);
    xdata[Register::A]->setValue(newValue);
    BOOST_LOG_TRIVIAL(debug)  << "A(=" <<newValue<<") <-- A  - carry - R" << Raddress << "([" << xMem->getName() << "])";
}

template<>
void InstrTemp2<Instructions::SUBB_A_DIRECT>::execution() {
    IP++;
    auto address = xdata[flashMemory[IP]];
    auto data = address->getValue();
    auto statusWord = xdata[Register::PSW];
    bool carry = statusWord->getBit(7);
    auto REG_A = xdata[Register::A]->getValue();
    int16_t newValue = (REG_A  - data).getValue()-carry;
    carry = newValue & 0x100;
    bool ov;
    statusWord->setBit(7, carry);
    statusWord->setBit(2, ov);
    xdata[Register::A]->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug)  << "A(=" << (newValue&0xFF) <<") <-- A  - carry - [" << address->getName() << "]";
}