//
// Created by developer on 2/1/16.
//

#ifndef CC2530SIM_T1CC2H_H
#define CC2530SIM_T1CC2H_H

#include "../MemoryLocation.h"
class T1CC2H : public MemoryLocation {
public:
    T1CC2H() :MemoryLocation(0xDF) {
    }
public:
    virtual std::string getName() override {
        return "T1CC2H";
    }
};
#endif //CC2530SIM_SLEEPCMD_H
