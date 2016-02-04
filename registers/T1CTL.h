//
// Created by developer on 2/1/16.
//

#ifndef CC2530SIM_T1CTL_H
#define CC2530SIM_T1CTL_H

#include "../MemoryLocation.h"
class T1CTL : public MemoryLocation {
public:
    T1CTL() :MemoryLocation(0xE4) {
    }
public:
    virtual std::string getName() override {
        return "T1CTL";
    }
};
#endif //CC2530SIM_SLEEPCMD_H
