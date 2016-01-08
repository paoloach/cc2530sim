//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_TCON_H
#define CC2530SIM_TCON_H

#include "../MemoryLocation.h"
class TCON : public MemoryLocation {
public:
    TCON() :MemoryLocation(0x88) {
    }
public:
    virtual std::string getName() override {
        return "TCON";
    }
};

#endif //CC2530SIM_TCON_H
