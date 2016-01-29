//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_RFIRQF0_H
#define CC2530SIM_RFIRQF0_H

#include "../MemoryLocation.h"
class RFIRQF0 : public MemoryLocation {
public:
    RFIRQF0() :MemoryLocation(0xE9) {

    }
public:
    virtual std::string getName() override {
        return "RFIRQF0";
    }
};

#endif //CC2530SIM_P0_H
