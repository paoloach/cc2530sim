//
// Created by developer on 1/22/16.
//

#include <boost/log/trivial.hpp>
#include "Instruction.h"


template<>
void InstrTemp3<Instructions::ORL_AND_DIRECT_A>::execution() {
    char op;
    bool isAnd = flashMemory[IP] & 0x10;
    IP++;
    auto address = xdata[flashMemory[IP]];
    Data8 newValue;
    if (isAnd) {
        newValue = address->getValue() & xdata.A->getValue();
        op = '&';
    } else {
        newValue = address->getValue() | xdata.A->getValue();
        op='|';
    }
    address->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "[" << address->getName() << "] <- A " << op <<" [" << address->getName() << "]";
}


template<>
void InstrTemp4<Instructions::ORL_AND_DIRECT_DATA>::execution() {
    char op;
    bool isAnd = flashMemory[IP] & 0x10;
    IP++;
    auto address = xdata[flashMemory[IP]];
    IP++;
    Data8 data = flashMemory[IP];
    IP++;
    Data8 newValue;
    if (isAnd) {
        newValue = address->getValue() & data;
        op = '&';
    } else {
        newValue = address->getValue() | data;
        op='|';
    }
    address->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "[" << address->getName() << "] <- " << data  << op <<" [" << address->getName() << "]";
}

template<>
void InstrTemp2<Instructions::ORL_AND_A_DATA>::execution() {
    char op;
    bool isAnd = flashMemory[IP] & 0x10;
    IP++;
    Data8 data(flashMemory[IP]);
    auto REG_A = xdata.A->getValue();
    auto newValue = data | REG_A;
    xdata.A->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "A(" << newValue << ") <-- A  | " << data;
}

template<>
void InstrTemp2<Instructions::ORL_AND_A_DIRECT>::execution() {
    char op;
    bool isAnd = flashMemory[IP] & 0x10;
    IP++;
    auto address = xdata[flashMemory[IP]];
    Data8 newValue;
    if (isAnd) {
        newValue = address->getValue() & xdata.A->getValue();
        op = '&';
    } else {
        newValue = address->getValue() | xdata.A->getValue();
        op='|';
    }
    xdata.A->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "A(" << newValue << ") <- A "<< op <<" [" << address->getName() << "]";
}

template<>
void InstrTemp2<Instructions::ORL_AND_A_AT_R0>::execution() {
    char op;
    bool isAnd = flashMemory[IP] & 0x10;
    uint16_t RAddress = registryUtil.getRAddress(flashMemory[IP] & 0x01);
    IP++;
    auto rn = xdata[RAddress];
    auto rVal = rn->getValue();
    auto address = xdata[rVal];
    Data8 newValue;
    if (isAnd) {
        newValue = address->getValue() & xdata.A->getValue();
        op = '&';
    } else {
        newValue = address->getValue() | xdata.A->getValue();
        op='|';
    }
    xdata.A->setValue(newValue);
    IP++;
    BOOST_LOG_TRIVIAL(debug) << "A(" << newValue << ") <- A "<< op <<" @R" << RAddress << "([" << xMem->getName() << "])";
}

template<>
void InstrTemp1<Instructions::ORL_AND_A_RN>::execution() {
    char op;
    bool isAnd = flashMemory[IP] & 0x10;
    int opcode = flashMemory[IP] & 0x07;
    uint16_t RAddress = registryUtil.getRAddress(opcode);
    IP++;
    auto rn = xdata[Raddress];
    Data8 newValue;
    if (isAnd) {
        newValue = rn->getValue() & xdata.A->getValue();
        op = '&';
    } else {
        newValue = rn->getValue() | xdata.A->getValue();
        op='|';
    }
    xdata.A->setValue(newValue);
    BOOST_LOG_TRIVIAL(debug) << "A(" << newValue << ") <-- A  "<< op <<" R" << opcode;
}