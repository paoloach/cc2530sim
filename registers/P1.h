//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_P1_H
#define CC2530SIM_P1_H

#include "../MemoryLocation.h"
class P1 : public MemoryLocation {
public:
    P1() :MemoryLocation(0x90) {
    }
public:
    virtual std::string getName() override {
        return "P1";
    }
};

#endif //CC2530SIM_P1_H
