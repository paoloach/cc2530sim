//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_SP_H
#define CC2530SIM_SP_H

#include "../MemoryLocation.h"
class SP : public MemoryLocation {
public:
    SP() :MemoryLocation(0x81) {

    }
public:
    virtual std::string getName() override {
        return "SP";
    }
};

#endif //CC2530SIM_SP_H
