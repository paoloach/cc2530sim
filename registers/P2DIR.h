//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_P2DIR_H
#define CC2530SIM_P2DIR_H

#include "../MemoryLocation.h"
class P2DIR : public MemoryLocation {
public:
    P2DIR() :MemoryLocation(0xFF) {

    }
public:
    virtual std::string getName() override {
        return "P2DIR";
    }
};

#endif //CC2530SIM_P0_H
