//
// Created by developer on 12/18/15.
//

#ifndef CC2530SIM_DPL0_H
#define CC2530SIM_DPL0_H

#include "../MemoryLocation.h"
class DPL0 : public MemoryLocation {
public:
    DPL0() :MemoryLocation(0x82) {

    }
public:
    virtual std::string getName() override {
        return "DPL0";
    }
};


#endif //CC2530SIM_DPL0_H
