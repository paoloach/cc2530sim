//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_S0CON_H
#define CC2530SIM_S0CON_H

#include "../MemoryLocation.h"
class S0CON : public MemoryLocation {
public:
    S0CON() :MemoryLocation(0x98) {
    }
public:
    virtual std::string getName() override {
        return "S0CON";
    }
};

#endif //CC2530SIM_S0CON_H
