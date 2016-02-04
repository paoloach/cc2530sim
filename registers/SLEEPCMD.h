//
// Created by developer on 2/1/16.
//

#ifndef CC2530SIM_SLEEPCMD_H
#define CC2530SIM_SLEEPCMD_H

#include "../MemoryLocation.h"
class SLEEPCMD : public MemoryLocation {
public:
    SLEEPCMD() :MemoryLocation(0xBE) {
    }
public:
    virtual std::string getName() override {
        return "SLEEPCMD";
    }
};
#endif //CC2530SIM_SLEEPCMD_H
