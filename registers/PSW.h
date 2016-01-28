//
// Created by developer on 1/28/16.
//

#ifndef CC2530SIM_PSW_H
#define CC2530SIM_PSW_H

#include "../MemoryLocation.h"
class PSW : public MemoryLocation {
public:
    PSW() :MemoryLocation(0xD0) {
    }
public:
    virtual std::string getName() override {
        return "PSW";
    }
};
#endif //CC2530SIM_PSW_H
