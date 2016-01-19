//
// Created by developer on 1/15/16.
//

#include <boost/log/trivial.hpp>
#include <sstream>
#include "Instruction.h"

template<>
void  InstrTemp4<Instructions::MOV_DIRECT_DIRECT>::execution() {
    IP++;
    auto addressDest = xdata[flashMemory[IP]];
    IP++;
    auto addressSrc = xdata[flashMemory[IP]];
    IP++;
    auto value = addressSrc->getValue();
    addressDest->setValue(value);
    BOOST_LOG_TRIVIAL(debug) << "[" << addressDest->getName() << "](" << (int) value << ") <-- [" <<
                             addressSrc->getName() << "]";
}

template<>
void InstrTemp3<Instructions::MOV_DIRECT_RN>::execution() {
    uint16_t Raddress = registryUtil.getRAddress(flashMemory[IP]);
    auto addressSrc = xdata[Raddress];
    IP++;
    auto addressDest = xdata[flashMemory[IP]];
    IP++;
    auto value = addressSrc->getValue();
    addressDest->setValue(value);
    BOOST_LOG_TRIVIAL(debug) << "[" << addressDest->getName() << "](" << (int) value << ") <-- R" << (Raddress & 0x7);
}


template<>
void InstrTemp2<Instructions::MOV_A_DIRECT>::execution() {
    IP++;
    uint8_t address = flashMemory[IP];
    uint8_t data = xdata[address]->getValue();
    xdata[Register::A]->setValue(data);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "A <-- [" << xdata[address]->getName() << "]";
}

template<>
void InstrTemp2<Instructions::MOV_A_AT_RN>::execution() {
    uint16_t rbit = flashMemory[IP] & 0x01;
    uint16_t Raddress = registryUtil.getRAddress(rbit);
    IP++;
    auto rn = xdata[Raddress];
    uint8_t rVal = rn->getValue();
    auto xMem = xdata[rVal];
    uint8_t data = xMem->getValue();
    xdata[Register::A]->setValue(data);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "A(" << (uint)data << ") <-- @R" << rbit << "[" << xMem->getName() << "]";
}

template<>
void InstrTemp1<Instructions::MOV_A_RN>::execution() {
    uint16_t rbit = flashMemory[IP] & 0x01;
    uint16_t Raddress = registryUtil.getRAddress(rbit);
    auto rn = xdata[Raddress];
    IP++;
    uint8_t data = rn->getValue();
    xdata[Register::A]->setValue(data);
    BOOST_LOG_TRIVIAL(debug) << "MOV A(" << (uint)data << ") <-- R" << rbit;
}