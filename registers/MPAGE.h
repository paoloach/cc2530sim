//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_MPAGE_H
#define CC2530SIM_MPAGE_H

#include "../MemoryLocation.h"
class MPAGE : public MemoryLocation {
public:
    MPAGE() :MemoryLocation(0x93) {

    }
public:
    virtual std::string getName() override {
        return "MPAGE";
    }
};

#endif //CC2530SIM_P0_H
