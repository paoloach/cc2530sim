//
// Created by developer on 2/1/16.
//

#ifndef CC2530SIM_T1CC0L_H
#define CC2530SIM_T1CC0L_H

#include "../MemoryLocation.h"
class T1CC0L : public MemoryLocation {
public:
    T1CC0L() :MemoryLocation(0xDA) {
    }
public:
    virtual std::string getName() override {
        return "T1CC0L";
    }
};
#endif //CC2530SIM_SLEEPCMD_H
