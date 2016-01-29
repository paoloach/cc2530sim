//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_P0IFG_H
#define CC2530SIM_P0IFG_H

#include "../MemoryLocation.h"
class P0IFG : public MemoryLocation {
public:
    P0IFG() :MemoryLocation(0x89) {

    }
public:
    virtual std::string getName() override {
        return "P0IFG";
    }
};

#endif //CC2530SIM_P0_H
