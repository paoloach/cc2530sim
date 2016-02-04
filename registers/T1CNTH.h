//
// Created by developer on 2/1/16.
//

#ifndef CC2530SIM_T1CNTH_H
#define CC2530SIM_T1CNTH_H

#include "../MemoryLocation.h"
class T1CNTH : public MemoryLocation {
public:
    T1CNTH() :MemoryLocation(0xE3) {
    }
public:
    virtual std::string getName() override {
        return "T1CNTH";
    }
};
#endif //CC2530SIM_SLEEPCMD_H
