//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_P0DIR_H
#define CC2530SIM_P0DIR_H

#include "../MemoryLocation.h"
class P0DIR : public MemoryLocation {
public:
    P0DIR() :MemoryLocation(0xFD) {

    }
public:
    virtual std::string getName() override {
        return "P0DIR";
    }
};

#endif //CC2530SIM_P0_H
