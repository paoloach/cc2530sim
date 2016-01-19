//
// Created by root on 11/6/15.
//

#ifndef CC2530_FLASHMEMORY_H
#define CC2530_FLASHMEMORY_H

#include <stdint.h>
#include <istream>
#include <ctype.h>
#include <vector>
#include "InstructionPointer.h"


class FlashMemory {
public:
    void loafFromString(std::istream & stream);

    uint8_t operator[](InstructionPointer addr);
    uint8_t operator[](uint16_t addr);
private:
    std::vector<uint8_t> memory;


};


#endif //CC2530_FLASHMEMORY_H
