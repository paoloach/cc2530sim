//
// Created by developer on 1/28/16.
//

#ifndef CC2530SIM_DPL1_H
#define CC2530SIM_DPL1_H
#include "../MemoryLocation.h"

class DPL1 : public MemoryLocation {
public:
    DPL1() :MemoryLocation(0x84) {

    }
public:
    virtual std::string getName() override {
        return "DPL1";
    }
};
#endif //CC2530SIM_DPL1_H
