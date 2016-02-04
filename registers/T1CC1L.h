//
// Created by developer on 2/1/16.
//

#ifndef CC2530SIM_T1CC1L_H
#define CC2530SIM_T1CC1L_H

#include "../MemoryLocation.h"
class T1CC1L : public MemoryLocation {
public:
    T1CC1L() :MemoryLocation(0xDC) {
    }
public:
    virtual std::string getName() override {
        return "T1CC1L";
    }
};
#endif //CC2530SIM_SLEEPCMD_H
