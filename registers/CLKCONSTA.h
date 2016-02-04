//
// Created by developer on 2/1/16.
//

#ifndef CC2530SIM_CLKCONSTA_H
#define CC2530SIM_CLKCONSTA_H

#include "../MemoryLocation.h"
class CLKCONSTA : public MemoryLocation {
public:
    CLKCONSTA() :MemoryLocation(0x9E) {
    }
public:
    virtual std::string getName() override {
        return "CLKCONSTA";
    }
};
#endif //CC2530SIM_SLEEPCMD_H
