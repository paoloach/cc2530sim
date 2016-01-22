//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_MEMCTR_H
#define CC2530SIM_MEMCTR_H

#include "../MemoryLocation.h"
class MEMCTR : public MemoryLocation {
public:
    MEMCTR() :MemoryLocation(0xC7) {

    }
public:
    virtual std::string getName() override {
        return "MEMCTR";
    }
};

#endif //CC2530SIM_P0_H
