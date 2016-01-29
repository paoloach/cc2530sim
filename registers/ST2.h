//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_ST2_H
#define CC2530SIM_ST2_H

#include "../MemoryLocation.h"
class ST2 : public MemoryLocation {
public:
    ST2() :MemoryLocation(0x97) {
    }
public:
    virtual std::string getName() override {
        return "ST2";
    }
};

#endif //CC2530SIM_S0CON_H
