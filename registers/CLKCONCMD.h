//
// Created by developer on 2/1/16.
//

#ifndef CC2530SIM_CLKCONCMD_H
#define CC2530SIM_CLKCONCMD_H

#include "../MemoryLocation.h"
class CLKCONCMD : public MemoryLocation {
public:
    CLKCONCMD() :MemoryLocation(0xC6) {
    }
public:
    virtual std::string getName() override {
        return "CLKCONCMD";
    }
};
#endif //CC2530SIM_SLEEPCMD_H
