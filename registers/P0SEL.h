//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_P0SEL_H
#define CC2530SIM_P0SEL_H

#include "../MemoryLocation.h"
class P0SEL : public MemoryLocation {
public:
    P0SEL() :MemoryLocation(0xF3) {

    }
public:
    virtual std::string getName() override {
        return "P0SEL";
    }
};

#endif //CC2530SIM_P0_H
