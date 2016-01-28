//
// Created by developer on 1/28/16.
//

#ifndef CC2530SIM_PCON_H
#define CC2530SIM_PCON_H
#include "../MemoryLocation.h"

class PCON : public MemoryLocation {
public:
    PCON() :MemoryLocation(0x87) {

    }
public:
    virtual std::string getName() override {
        return "PCON";
    }
};
#endif //CC2530SIM_PCON_H
