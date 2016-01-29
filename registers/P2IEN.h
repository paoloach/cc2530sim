//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_P2IEN_H
#define CC2530SIM_P2IEN_H

#include "../MemoryLocation.h"
class P2IEN : public MemoryLocation {
public:
    P2IEN() :MemoryLocation(0xAC) {

    }
public:
    virtual std::string getName() override {
        return "P2IEN";
    }
};

#endif //CC2530SIM_P0_H
