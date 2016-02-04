//
// Created by developer on 2/1/16.
//

#ifndef CC2530SIM_T1CCTL2_H
#define CC2530SIM_T1CCTL2_H

#include "../MemoryLocation.h"
class T1CCTL2 : public MemoryLocation {
public:
    T1CCTL2() :MemoryLocation(0xE7) {
    }
public:
    virtual std::string getName() override {
        return "T1CCTL2";
    }
};
#endif //CC2530SIM_SLEEPCMD_H
