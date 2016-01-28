//
// Created by developer on 1/28/16.
//

#ifndef CC2530SIM_DPS_H
#define CC2530SIM_DPS_H

#include "../MemoryLocation.h"
class DPS : public MemoryLocation {
public:
    DPS() :MemoryLocation(0x92) {

    }
public:
    virtual std::string getName() override {
        return "DPS";
    }
};
#endif //CC2530SIM_DPS_H
