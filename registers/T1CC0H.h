//
// Created by developer on 2/1/16.
//

#ifndef CC2530SIM_T1CC0H_H
#define CC2530SIM_T1CC0H_H

#include "../MemoryLocation.h"
class T1CC0H : public MemoryLocation {
public:
    T1CC0H() :MemoryLocation(0xDB) {
    }
public:
    virtual std::string getName() override {
        return "T1CC0H";
    }
};
#endif //CC2530SIM_SLEEPCMD_H
