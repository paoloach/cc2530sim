//
// Created by developer on 1/8/16.
//

#include <stdint.h>
#include "Instruction.h"

template<>
void InstrTemp2<Instructions::SUBB_A_DATA>::execution() {
    IP++;
    auto statusWord = xdata[Register::PSW];
    int8_t data = flashMemory[IP];
    int8_t REG_A = xdata[Register::A]->getValue();
    bool carry = statusWord->getBit(7);
    int16_t newValue = REG_A + carry -data;
    carry = newValue & 0x100;
    bool ov;
    statusWord->setBit(7, carry);
    statusWord->setBit(2, ov);
    xdata[Register::A]->setValue(newValue);
    IP++;
    std::cout << "A (" << newValue << ") <-- A - C ";
    if (data >= 0) {
        std::cout << " - ";
    } else {
        std::cout << " + ";
        data = -data;
    }
    std::cout << std::setfill('0') << std::setw(2) << std::hex << (uint) data << " + carry" << std::endl;
}

template<>
void InstrTemp1<Instructions::SUBB_A_RN>::execution() {
    uint16_t Raddress = registryUtil.getRAddress(flashMemory[IP]);
    IP++;
    auto rn = xdata[Raddress];
    auto statusWord = xdata[Register::PSW];
    int8_t REG_A = xdata[Register::A]->getValue();
    bool carry = statusWord->getBit(7);
    int16_t newValue = REG_A - carry - rn->getValue();
    carry = newValue & 0x100;
    bool ov;
    statusWord->setBit(7, carry);
    statusWord->setBit(2, ov);
    xdata[Register::A]->setValue(newValue);
    std::cout << "A(" << newValue <<") <-- A - C - R" + Raddress << std::endl;
}

template<>
void InstrTemp2<Instructions::SUBB_A_AT_RN>::execution() {
    uint16_t Raddress = registryUtil.getRAddress(flashMemory[IP] & 0x01);
    IP++;
    auto rn = xdata[Raddress];
    uint8_t rVal = rn->getValue();
    auto xMem = xdata[rVal];
    auto statusWord = xdata[Register::PSW];
    bool carry = statusWord->getBit(7);
    int8_t REG_A = xdata[Register::A]->getValue();
    int16_t newValue = REG_A- carry - xMem->getValue();
    carry = newValue & 0x100;
    bool ov;
    statusWord->setBit(7, carry);
    statusWord->setBit(2, ov);
    xdata[Register::A]->setValue(newValue);
    std::cout << "A(" <<newValue<<") <-- A  - carry - R" << Raddress << "([" << xMem->getName() << "])" << std::endl;
}

template<>
void InstrTemp2<Instructions::SUBB_A_DIRECT>::execution() {
    IP++;
    auto address = xdata[flashMemory[IP]];
    uint8_t data = address->getValue();
    auto statusWord = xdata[Register::PSW];
    bool carry = statusWord->getBit(7);
    int8_t REG_A = xdata[Register::A]->getValue();
    int16_t newValue = REG_A -carry - data;
    carry = newValue & 0x100;
    bool ov;
    statusWord->setBit(7, carry);
    statusWord->setBit(2, ov);
    xdata[Register::A]->setValue(newValue);
    IP++;
    std::cout << "A(";
    std::cout << (newValue&0xFF) <<") <-- A  - carry - [" << address->getName() << "]" << std::endl;
}