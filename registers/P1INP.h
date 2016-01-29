//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_P1INP_H
#define CC2530SIM_P1INP_H

#include "../MemoryLocation.h"
class P1INP : public MemoryLocation {
public:
    P1INP() :MemoryLocation(0xF6) {

    }
public:
    virtual std::string getName() override {
        return "P1INP";
    }
};

#endif //CC2530SIM_P0_H
