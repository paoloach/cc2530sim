//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_P2IFG_H
#define CC2530SIM_P2IFG_H

#include "../MemoryLocation.h"
class P2IFG : public MemoryLocation {
public:
    P2IFG() :MemoryLocation(0x8B) {
    }
public:
    virtual std::string getName() override {
        return "P2IFG";
    }
};

#endif //CC2530SIM_P1_H
