//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_P2_H
#define CC2530SIM_P2_H

#include "../MemoryLocation.h"
class P2 : public MemoryLocation {
public:
    P2() :MemoryLocation(0xA0) {
    }
public:
    virtual std::string getName() override {
        return "P2";
    }
};

#endif //CC2530SIM_P2_H
