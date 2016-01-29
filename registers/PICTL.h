//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_PICTL_H
#define CC2530SIM_PICTL_H

#include "../MemoryLocation.h"
class PICTL : public MemoryLocation {
public:
    PICTL() :MemoryLocation(0x8C) {
    }
public:
    virtual std::string getName() override {
        return "PICTL";
    }
};

#endif //CC2530SIM_P1_H
