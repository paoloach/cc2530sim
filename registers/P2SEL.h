//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_P2SEL_H
#define CC2530SIM_P2SEL_H

#include "../MemoryLocation.h"
class P2SEL : public MemoryLocation {
public:
    P2SEL() :MemoryLocation(0xF5) {

    }
public:
    virtual std::string getName() override {
        return "P2SEL";
    }
};

#endif //CC2530SIM_P0_H
