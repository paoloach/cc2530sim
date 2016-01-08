//
// Created by developer on 12/11/15.
//

#include "RegistryUtil.h"

uint16_t RegistryUtil::getRAddress(uint8_t opcode) {
    uint8_t reg = opcode & 0x07;
    return ((xData[Register::PSW]->getValue() & 0x3) << 3) | reg;
}

uint16_t RegistryUtil::getDPH() {
    if (xData[Register::DPS]->getBit(0)){
        return (uint16_t)Register::DPH1;
    } else {
        return (uint16_t)Register::DPH0;
    }
}

uint16_t RegistryUtil::getDPL() {
    if (xData[Register::DPS]->getBit(0)){
        return (uint16_t)Register::DPL1;
    } else {
        return (uint16_t)Register::DPL0;
    }
}

uint16_t RegistryUtil::getXAddressFromBitAddress(uint8_t bitAddress) {
    uint8_t reg = bitAddress / 8;
    if (reg <=15){
        return 0x20 + reg;
    }
    return reg*8;
}
