//
// Created by developer on 1/28/16.
//

#ifndef CC2530SIM_ENCDO_H
#define CC2530SIM_ENCDO_H
#include "../MemoryLocation.h"
class ENCDO : public MemoryLocation {
public:
    ENCDO() :MemoryLocation(0xB2) {

    }
public:
    virtual std::string getName() override {
        return "ENCDO";
    }
};
#endif //CC2530SIM_ENCDI_H
