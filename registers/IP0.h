//
// Created by developer on 1/28/16.
//

#ifndef CC2530SIM_IP0_H
#define CC2530SIM_IP0_H


#include "../MemoryLocation.h"
class IP0 : public MemoryLocation {
public:
    IP0() :MemoryLocation(0xA9) {
    }
public:
    virtual std::string getName() override {
        return "IP0";
    }
};

#endif //CC2530SIM_IP0_H
