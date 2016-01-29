//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_PERCFG_H
#define CC2530SIM_PERCFG_H

#include "../MemoryLocation.h"
class PERCFG : public MemoryLocation {
public:
    PERCFG() :MemoryLocation(0xF1) {

    }
public:
    virtual std::string getName() override {
        return "PERCFG";
    }
};

#endif //CC2530SIM_P0_H
