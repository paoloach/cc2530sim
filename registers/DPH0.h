//
// Created by developer on 12/18/15.
//

#ifndef CC2530SIM_DPH0_H
#define CC2530SIM_DPH0_H

#include "../MemoryLocation.h"
class DPH0 : public MemoryLocation {
public:
    DPH0() :MemoryLocation(0x83) {

    }
public:
    virtual std::string getName() override {
        return "DPH0";
    }

};


#endif //CC2530SIM_DPH0_H
