//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_STLOAD_H
#define CC2530SIM_STLOAD_H

#include "../MemoryLocation.h"
class STLOAD : public MemoryLocation {
public:
    STLOAD() :MemoryLocation(0xAD) {
    }
public:
    virtual std::string getName() override {
        return "STLOAD";
    }
};

#endif //CC2530SIM_S0CON_H
