//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_ST0_H
#define CC2530SIM_ST0_H

#include "../MemoryLocation.h"
class ST0 : public MemoryLocation {
public:
    ST0() :MemoryLocation(0x95) {
    }
public:
    virtual std::string getName() override {
        return "ST0";
    }
};

#endif //CC2530SIM_S0CON_H
