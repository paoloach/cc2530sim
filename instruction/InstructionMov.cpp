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
    BOOST_LOG_TRIVIAL(debug) << "[" << addressDest->getName() << "](" << (int)value << ") <-- [" << addressSrc->getName() << "]";
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
    BOOST_LOG_TRIVIAL(debug) << "[" << addressDest->getName() << "](" << (int)value << ") <-- R" << (Raddress&0x7);
}