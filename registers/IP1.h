//
// Created by developer on 1/28/16.
//

#ifndef CC2530SIM_IP1_H
#define CC2530SIM_IP1_H


#include "../MemoryLocation.h"
class IP1 : public MemoryLocation {
public:
    IP1() :MemoryLocation(0xB9) {
    }
public:
    virtual std::string getName() override {
        return "IP1";
    }
};

#endif //CC2530SIM_IP0_H
