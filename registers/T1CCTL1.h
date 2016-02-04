//
// Created by developer on 2/1/16.
//

#ifndef CC2530SIM_T1CCTL1_H
#define CC2530SIM_T1CCTL1_H

#include "../MemoryLocation.h"
class T1CCTL1 : public MemoryLocation {
public:
    T1CCTL1() :MemoryLocation(0xE6) {
    }
public:
    virtual std::string getName() override {
        return "T1CCTL1";
    }
};
#endif //CC2530SIM_SLEEPCMD_H
