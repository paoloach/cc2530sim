//
// Created by developer on 11/20/15.
//

#ifndef CC2530SIM_MEMORYLOCATION_H
#define CC2530SIM_MEMORYLOCATION_H


#include <bitset>
#include <stdint.h>

class MemoryLocation {
public:
    MemoryLocation():value(0){}
    MemoryLocation(uint8_t value):value(value){}

    virtual bool getBit(int index){
        return std::bitset<8>(value)[index];
    }

    virtual void setBit(int index, bool binValue){
        auto bits = std::bitset<8>(value);
        bits[index] = binValue;
    }

    virtual void setValue(uint8_t newValue){
        value = newValue;
    }

    virtual uint8_t getValue() {
        return value;
    }
protected:
    uint8_t value;
};


#endif //CC2530SIM_MEMORYLOCATION_H
