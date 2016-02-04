//
// Created by developer on 2/1/16.
//

#ifndef CC2530SIM_SLEEPSTA_H
#define CC2530SIM_SLEEPSTA_H

#include "../MemoryLocation.h"
class SLEEPSTA : public MemoryLocation {
public:
    SLEEPSTA() :MemoryLocation(0x9D) {
    }
public:
    virtual std::string getName() override {
        return "SLEEPSTA";
    }
};
#endif //CC2530SIM_SLEEPCMD_H
