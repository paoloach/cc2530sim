//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_P0_H
#define CC2530SIM_P0_H

#include "../MemoryLocation.h"
class P0 : public MemoryLocation {
public:
    P0() :MemoryLocation(0x80) {

    }
public:
    virtual std::string getName() override {
        return "P0";
    }
};

#endif //CC2530SIM_P0_H
