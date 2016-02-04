//
// Created by developer on 2/1/16.
//

#ifndef CC2530SIM_T1CC1H_H
#define CC2530SIM_T1CC1H_H

#include "../MemoryLocation.h"
class T1CC1H : public MemoryLocation {
public:
    T1CC1H() :MemoryLocation(0xDD) {
    }
public:
    virtual std::string getName() override {
        return "T1CC1H";
    }
};
#endif //CC2530SIM_SLEEPCMD_H
