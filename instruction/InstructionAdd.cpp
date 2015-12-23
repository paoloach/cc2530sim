//
// Created by developer on 12/21/15.
//
#include <stdint.h>
#include "Instruction.h"


template<>
std::shared_ptr<Instruction> InstrTemp2<Instructions::ADD_A_DATA>::execution() {
    IP++;
    int8_t data = flashMemory[IP];
    int8_t REG_A = xdata[Register::A]->getValue();
    int16_t newValue = data + REG_A;
    bool  carry = newValue & 0x100;
    bool ov;
    auto statusWord =  xdata[Register::PSW];
    statusWord->setBit(7, carry);
    statusWord->setBit(2, ov);
    xdata[Register::A]->setValue(newValue);
    IP++;
    std::cout << "A <-- A  + 0x" << std::setfill('0')  << std::setw(2) << std::hex << (uint)data << std::endl;
}

template<>
std::shared_ptr<Instruction> InstrTemp1<Instructions::ADD_A_RN>::execution() {
    uint16_t Raddress = registryUtil.getRAddress(flashMemory[IP]);
    IP++;
    auto rn = xdata[Raddress];
    int8_t REG_A = xdata[Register::A]->getValue();
    int16_t newValue = rn->getValue() + REG_A;
    bool  carry = newValue & 0x100;
    bool ov;
    auto statusWord =  xdata[Register::PSW];
    statusWord->setBit(7, carry);
    statusWord->setBit(2, ov);
    xdata[Register::A]->setValue(newValue);
    std::cout << "A <-- A  + R" + Raddress << std::endl;
}

template<>
void InstrTemp1<Instructions::ADD_A_AT_RN>::execution() {
 //   uint16_t Raddress = registryUtil.getRAddress(flashMemory[IP] & 0x01);
    IP++;
//    auto rn = xdata[Raddress];
//    uint8_t  rVal = rn->getValue();
//    auto xMem = xdata[rVal];
//    int8_t REG_A = xdata[Register::A]->getValue();
//    int16_t newValue = xMem->getValue() + REG_A;
//    bool  carry = newValue & 0x100;
//    bool ov;
//    auto statusWord =  xdata[Register::PSW];
//    statusWord->setBit(7, carry);
//    statusWord->setBit(2, ov);
//    xdata[Register::A]->setValue(newValue);
//    std::cout << "A <-- A  +@R" << Raddress  << "([" << xMem->getName() << "])" << std::endl;
}

template<>
std::shared_ptr<Instruction> InstrTemp2<Instructions::ADD_A_RN>::execution() {
    IP++;
    uint8_t address = flashMemory[IP];
    auto xMem = xdata[address];
    int8_t REG_A = xdata[Register::A]->getValue();
    int16_t newValue = xMem->getValue() + REG_A;
    bool  carry = newValue & 0x100;
    bool ov;
    auto statusWord =  xdata[Register::PSW];
    statusWord->setBit(7, carry);
    statusWord->setBit(2, ov);
    xdata[Register::A]->setValue(newValue);
    std::cout << "A <-- A  + [" +xMem->getName() << "]" <<  std::endl;
}