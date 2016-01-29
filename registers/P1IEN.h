//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_P1IEN_H
#define CC2530SIM_P1IEN_H

#include "../MemoryLocation.h"
class P1IEN : public MemoryLocation {
public:
    P1IEN() :MemoryLocation(0x8D) {

    }
public:
    virtual std::string getName() override {
        return "P1IEN";
    }
};

#endif //CC2530SIM_P0_H
