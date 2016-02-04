//
// Created by developer on 2/1/16.
//

#ifndef CC2530SIM_T1CC2L_H
#define CC2530SIM_T1CC2L_H

#include "../MemoryLocation.h"
class T1CC2L : public MemoryLocation {
public:
    T1CC2L() :MemoryLocation(0xDE) {
    }
public:
    virtual std::string getName() override {
        return "T1CC2L";
    }
};
#endif //CC2530SIM_SLEEPCMD_H
