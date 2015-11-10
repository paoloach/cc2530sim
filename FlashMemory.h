//
// Created by root on 11/6/15.
//

#ifndef CC2530_FLASHMEMORY_H
#define CC2530_FLASHMEMORY_H

#include <stdint.h>
#include <istream>
#include <ctype.h>


class FlashMemory {
public:
    void loafFromString(std::istream & stream);
private:
    uint8_t data[0x4000];


};


#endif //CC2530_FLASHMEMORY_H
