//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_ST1_H
#define CC2530SIM_ST1_H

#include "../MemoryLocation.h"
class ST1 : public MemoryLocation {
public:
    ST1() :MemoryLocation(0x96) {
    }
public:
    virtual std::string getName() override {
        return "ST1";
    }
};

#endif //CC2530SIM_S0CON_H
