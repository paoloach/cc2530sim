//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_P1DIR_H
#define CC2530SIM_P1DIR_H

#include "../MemoryLocation.h"
class P1DIR : public MemoryLocation {
public:
    P1DIR() :MemoryLocation(0xFE) {

    }
public:
    virtual std::string getName() override {
        return "P1DIR";
    }
};

#endif //CC2530SIM_P0_H
