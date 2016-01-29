//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_P0INP_H
#define CC2530SIM_P0INP_H

#include "../MemoryLocation.h"
class P0INP : public MemoryLocation {
public:
    P0INP() :MemoryLocation(0x8F) {

    }
public:
    virtual std::string getName() override {
        return "P0INP";
    }
};

#endif //CC2530SIM_P0_H
