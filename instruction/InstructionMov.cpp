//
// Created by developer on 1/15/16.
//

#include <boost/log/trivial.hpp>
#include "Instruction.h"

template<>
void  InstrTemp4<Instructions::MOV_DIRECT_DIRECT>::execution() {
    IP++;
    auto addressSrc = xdata[flashMemory[IP]];
    IP++;
    auto addressDest = xdata[flashMemory[IP]];
    IP++;
    auto value = addressSrc->getValue();
    addressDest->setValue(value);
    BOOST_LOG_TRIVIAL(debug) << "[" << addressDest->getName() << "](" <<  value << ") <-- [" <<
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
    BOOST_LOG_TRIVIAL(debug) << "MOV [" << addressDest->getName() << "](" <<  value << ") <-- R" <<
                             (Raddress & 0x7) <<" [" << xdata[4]->getValue() << "]";
}


template<>
void InstrTemp2<Instructions::MOV_A_DIRECT>::execution() {
    IP++;
    auto address = flashMemory[IP];
    auto data = xdata[address]->getValue();
    xdata.A->setValue(data);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "MOV A(=" <<  data << ") <-- [" << xdata[address]->getName() << "]";
}

template<>
void InstrTemp2<Instructions::MOV_A_AT_RN>::execution() {
    uint16_t rbit = flashMemory[IP] & 0x01;
    uint16_t Raddress = registryUtil.getRAddress(rbit);
    IP++;
    auto rn = xdata[Raddress];
    auto rVal = rn->getValue();
    auto xMem = xdata[rVal];
    auto data = xMem->getValue();
    xdata[Register::A]->setValue(data);
    BOOST_LOG_TRIVIAL(debug) << "MOV A(=" <<  data << ") <-- @R" << rbit << "[" << xMem->getName() << "]";
}

template<>
void InstrTemp1<Instructions::MOV_A_RN>::execution() {
    uint16_t rbit = flashMemory[IP] & 0x07;
    uint16_t Raddress = registryUtil.getRAddress(rbit);
    auto rn = xdata[Raddress];
    IP++;
    auto data = rn->getValue();
    xdata[Register::A]->setValue(data);
    BOOST_LOG_TRIVIAL(debug) << "MOV A(=" << data << ") <-- R" << rbit;
}

template<>
void InstrTemp2<Instructions::MOV_DIRECT_A>::execution() {
    IP++;
    uint8_t address = flashMemory[IP];
    auto dest = xdata[address];
    auto data = xdata.A->getValue();
    dest->setValue(data);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "[" << dest->getName() << "](" <<  data << ") <-- A";
}

template<>
void InstrTemp2<Instructions::MOV_AT_RN_A>::execution() {
    uint16_t rbit = flashMemory[IP] & 0x01;
    uint16_t Raddress = registryUtil.getRAddress(rbit);
    IP++;
    auto rn = xdata[Raddress];
    auto rVal = rn->getValue();
    auto dest = xdata[rVal];
    auto data = xdata.A->getValue();
    dest->setValue(data);
    BOOST_LOG_TRIVIAL(debug) << "@R" << rbit << "[" << dest->getName() << "](" << data << ") <-- A";
}

template<>
void InstrTemp1<Instructions::MOV_RN_A>::execution() {
    uint16_t rbit = flashMemory[IP] & 0x07;
    uint16_t Raddress = registryUtil.getRAddress(rbit);
    auto dest = xdata[Raddress];
    IP++;
    auto data = xdata.A->getValue();
    dest->setValue(data);
    BOOST_LOG_TRIVIAL(debug) << "MOV R" << rbit << "(" <<  data << ") <-- A";
}

template<>
void InstrTemp4<Instructions::MOV_RN_DIRECT>::execution() {
    uint16_t Raddress = registryUtil.getRAddress(flashMemory[IP]);
    IP++;
    auto address = flashMemory[IP];
    auto data = xdata[address]->getValue();
    xdata[Raddress]->setValue(data);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "MOV R" << (Raddress & 0x7) << "(=" << data  << ") <--  [" << xdata[address]->getName() << "]";
}
