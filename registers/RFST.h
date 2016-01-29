//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_RFST_H
#define CC2530SIM_RFST_H

#include "../MemoryLocation.h"
class RFST : public MemoryLocation {
public:
    RFST() :MemoryLocation(0xE1) {

    }
public:
    virtual std::string getName() override {
        return "RFST";
    }
};

#endif //CC2530SIM_P0_H
