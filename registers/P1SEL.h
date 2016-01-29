//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_P1SEL_H
#define CC2530SIM_P1SEL_H

#include "../MemoryLocation.h"
class P1SEL : public MemoryLocation {
public:
    P1SEL() :MemoryLocation(0xF4) {

    }
public:
    virtual std::string getName() override {
        return "P1SEL";
    }
};

#endif //CC2530SIM_P0_H
