//
// Created by developer on 1/22/16.
//

#include <boost/log/trivial.hpp>
#include "Instruction.h"


template<>
void InstrTemp3<Instructions::ORL_DIRECT_A>::execution() {
    IP++;
    auto address = xdata[flashMemory[IP]];
    auto newValue = address->getValue() | xdata.A->getValue();
    address->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "[" << address->getName() << "] <- A | [" << address->getName() << "]";
}


template<>
void InstrTemp4<Instructions::ORL_DIRECT_DATA>::execution() {
    IP++;
    auto address = xdata[flashMemory[IP]];
    IP++;
    Data8 data = flashMemory[IP];
    IP++;
    auto newValue = address->getValue() | data;
    address->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "[" << address->getName() << "] <- " << data << " | [" << address->getName() << "]";
}

template<>
void InstrTemp2<Instructions::ORL_A_DATA>::execution() {
    IP++;
    Data8 data(flashMemory[IP]);
    auto REG_A = xdata.A->getValue();
    auto newValue = data | REG_A;
    xdata.A->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "A(" << newValue << ") <-- A  | " << data;
}

template<>
void InstrTemp2<Instructions::ORL_A_DIRECT>::execution() {
    IP++;
    auto address = xdata[flashMemory[IP]];
    auto newValue = address->getValue() | xdata.A->getValue();
    xdata.A->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "A(" << newValue << ") <- A | [" << address->getName() << "]";
}

template<>
void InstrTemp2<Instructions::ORL_A_AT_R0>::execution() {
    uint16_t RAddress = registryUtil.getRAddress(flashMemory[IP] & 0x01);
    IP++;
    auto rn = xdata[RAddress];
    auto rVal = rn->getValue();
    auto address = xdata[rVal];
    auto newValue = address->getValue() | xdata.A->getValue();
    xdata.A->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "A(" << newValue << ") <- A | @R" << RAddress << "([" << xMem->getName() << "])";
}

template<>
void InstrTemp1<Instructions::ORL_A_RN>::execution() {
    int opcode = flashMemory[IP] & 0x07;
    uint16_t RAddress = registryUtil.getRAddress(opcode);
    IP++;
    auto rn = xdata[Raddress];
    auto newValue = rn->getValue() | xdata.A->getValue();
    xdata.A->setValue(newValue);
    BOOST_LOG_TRIVIAL(debug) << "A(" << newValue << ") <-- A  + R" << opcode;
}