//
// Created by developer on 1/28/16.
//

#ifndef CC2530SIM_DPH1_H
#define CC2530SIM_DPH1_H
#include "../MemoryLocation.h"

class DPH1 : public MemoryLocation {
public:
    DPH1() :MemoryLocation(0x85) {

    }
public:
    virtual std::string getName() override {
        return "DPH1";
    }
};
#endif //CC2530SIM_DPL1_H
