//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_S1CON_H
#define CC2530SIM_S1CON_H

#include "../MemoryLocation.h"
class S1CON : public MemoryLocation {
public:
    S1CON() :MemoryLocation(0x9B) {
    }
public:
    virtual std::string getName() override {
        return "S1CON";
    }
};

#endif //CC2530SIM_S0CON_H
