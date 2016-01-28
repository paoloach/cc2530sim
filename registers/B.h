//
// Created by developer on 12/18/15.
//

#ifndef CC2530SIM_B_H
#define CC2530SIM_B_H

#include "../MemoryLocation.h"
class B : public MemoryLocation {
public:
    B() :MemoryLocation(0xF0) {

    }
public:
    virtual std::string getName() override {
        return "B";
    }
};


#endif //CC2530SIM_ACC_H
