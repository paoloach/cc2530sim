//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_APCFG_H
#define CC2530SIM_APCFG_H

#include "../MemoryLocation.h"
class APCFG : public MemoryLocation {
public:
    APCFG() :MemoryLocation(0xF2) {

    }
public:
    virtual std::string getName() override {
        return "APCFG";
    }
};

#endif //CC2530SIM_P0_H
