//
// Created by root on 11/9/15.
//

#include "IntelHexData.h"


IntelHexData::IntelHexData(uint32_t address, IntelHexStatus & status, std::vector<uint8_t> &&data) :address(address), status(status),data(data){
}

void IntelHexData::execute(std::vector<uint8_t> & memory) {
    uint32_t  realAddress = (status.extendLinearAddress << 16) + address;
    if (memory.size() < realAddress){
        memory.resize(realAddress, 0);
    }
    for(uint8_t byte: data){
        memory.push_back(byte);
    }
}
