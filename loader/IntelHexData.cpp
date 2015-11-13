//
// Created by root on 11/9/15.
//

#include "IntelHexData.h"


IntelHexData::IntelHexData(uint32_t address, std::vector<uint8_t> &&data) :address(address), data(data){
}

void IntelHexData::execute(std::vector<uint8_t> & memory) {
    if (memory.size() < address){
        memory.resize(address, 0);
    }
    for(uint8_t byte: data){
        memory.push_back(byte);
    }
}
