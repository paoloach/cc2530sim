//
// Created by developer on 2/1/16.
//

#ifndef CC2530SIM_T1CCTL0_H
#define CC2530SIM_T1CCTL0_H

#include "../MemoryLocation.h"
class T1CCTL0 : public MemoryLocation {
public:
    T1CCTL0() :MemoryLocation(0xE5) {
    }
public:
    virtual std::string getName() override {
        return "T1CCTL0";
    }
};
#endif //CC2530SIM_SLEEPCMD_H
