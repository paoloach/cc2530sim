//
// Created by developer on 1/5/16.
//
#include <stdint.h>
#include "Instruction.h"

template<>
void InstrTemp3<Instructions::XCH_A_DIRECT>::execution() {
    IP++;
    auto address = xdata[flashMemory[IP]];
    uint8_t data = address->getValue();
    int8_t REG_A = xdata[Register::A]->getValue();
    xdata[Register::A]->setValue(data);
    address->setValue(REG_A);
    IP++;
    std::cout << "A <-> [" << address->getName() <<"]"  << std::endl;
}

template<>
void InstrTemp3<Instructions::XCH_A_AT_RN>::execution() {
    uint16_t Raddress = registryUtil.getRAddress(flashMemory[IP] & 0x01);
    IP++;
    auto rn = xdata[Raddress];
    uint8_t  rVal = rn->getValue();
    auto xMem = xdata[rVal];
    int8_t REG_A = xdata[Register::A]->getValue();
    xdata[Register::A]->setValue(xMem->getValue());
    xMem->setValue(REG_A);
    std::cout << "A <-> @R" << Raddress  << "([" << xMem->getName() << "])" << std::endl;
}


template<>
void InstrTemp2<Instructions::XCH_A_RN>::execution() {
    uint16_t Raddress = registryUtil.getRAddress(flashMemory[IP]);
    IP++;
    auto rn = xdata[Raddress];
    int8_t REG_A = xdata[Register::A]->getValue();
    xdata[Register::A]->setValue(rn->getValue());
    rn->setValue(REG_A);
    std::cout << "A <-> R" + Raddress << std::endl;
}