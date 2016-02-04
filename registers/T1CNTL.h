//
// Created by developer on 2/1/16.
//

#ifndef CC2530SIM_T1CNTL_H
#define CC2530SIM_T1CNTL_H

#include "../MemoryLocation.h"
class T1CNTL : public MemoryLocation {
public:
    T1CNTL() :MemoryLocation(0xE2) {
    }
public:
    virtual std::string getName() override {
        return "T1CNTL";
    }
};
#endif //CC2530SIM_SLEEPCMD_H
