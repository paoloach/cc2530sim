//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_P0IEN_H
#define CC2530SIM_P0IEN_H

#include "../MemoryLocation.h"
class P0IEN : public MemoryLocation {
public:
    P0IEN() :MemoryLocation(0xAB) {

    }
public:
    virtual std::string getName() override {
        return "P0IEN";
    }
};

#endif //CC2530SIM_P0_H
