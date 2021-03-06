//
// Created by developer on 11/20/15.
//

#ifndef CC2530SIM_MEMORYLOCATION_H
#define CC2530SIM_MEMORYLOCATION_H


#include <bitset>
#include <stdint.h>
#include <sstream>
#include <iomanip>
#include "Data8.h"

class MemoryLocation {
public:
    MemoryLocation(uint16_t address):value(0),address(address){
        std::stringstream stream;
        stream << std::setw(4) << std::setfill('0') << std::hex << address;
        name = stream.str();
    }
    MemoryLocation(uint16_t address, uint8_t value):value(value),address(address){
        std::stringstream stream;
        stream << "0x" << std::setw(4) << std::setfill('0') << std::hex << address;
        name = stream.str();
    }

    virtual bool getBit(int index){
        return  value.getBit(index);
    }

    virtual void setBit(int index, bool binValue){
        value.setBit(index,binValue);
    }

    virtual void setValue(Data8 newValue){
        value = newValue;
    }

    virtual Data8 getValue() {
        return value;
    }

    virtual std::string getName() {
        return name;
    }
protected:
    Data8 value;
    uint16_t address;
    std::string name;
};


#endif //CC2530SIM_MEMORYLOCATION_H
