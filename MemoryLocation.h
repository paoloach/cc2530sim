//
// Created by developer on 11/20/15.
//

#ifndef CC2530SIM_MEMORYLOCATION_H
#define CC2530SIM_MEMORYLOCATION_H


#include <bitset>
#include <stdint.h>

class MemoryLocation {
public:
    MemoryLocation(uint8_t value):value(value){}

    bool getBit(int index){
        return std::bitset<8>(value)[index];
    }
protected:
    uint8_t value;
};


#endif //CC2530SIM_MEMORYLOCATION_H
