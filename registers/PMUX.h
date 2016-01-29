//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_PMUX_H
#define CC2530SIM_PMUX_H

#include "../MemoryLocation.h"
class PMUX : public MemoryLocation {
public:
    PMUX() :MemoryLocation(0xAE) {

    }
public:
    virtual std::string getName() override {
        return "PMUX";
    }
};

#endif //CC2530SIM_P0_H
