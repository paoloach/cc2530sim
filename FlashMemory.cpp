//
// Created by root on 11/6/15.
//

#include <string>
#include "FlashMemory.h"
#include "loader/IntelHexLoader.h"

void FlashMemory::loafFromString(std::istream &stream) {
    IntelHexLoader::load(stream, memory);
}

uint8_t FlashMemory::operator[](InstructionPointer addr) {
    if (memory.size() < addr.getValue()){
        return 0xFF;
    } else {
        return memory[addr.getValue()];
    }
}


uint8_t FlashMemory::operator[](uint16_t addr) {
    if (memory.size() < addr){
        return 0xFF;
    } else {
        return memory[addr];
    }
}