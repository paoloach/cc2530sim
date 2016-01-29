//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_P1IFG_H
#define CC2530SIM_P1IFG_H

#include "../MemoryLocation.h"
class P1IFG : public MemoryLocation {
public:
    P1IFG() :MemoryLocation(0x8A) {
    }
public:
    virtual std::string getName() override {
        return "P1IFG";
    }
};

#endif //CC2530SIM_P1_H
