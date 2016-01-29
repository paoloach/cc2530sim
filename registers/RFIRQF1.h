//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_RFIRQF1_H
#define CC2530SIM_RFIRQF1_H

#include "../MemoryLocation.h"
class RFIRQF1 : public MemoryLocation {
public:
    RFIRQF1() :MemoryLocation(0x91) {

    }
public:
    virtual std::string getName() override {
        return "RFIRQF1";
    }
};

#endif //CC2530SIM_P0_H
