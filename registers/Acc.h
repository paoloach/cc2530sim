//
// Created by developer on 12/18/15.
//

#ifndef CC2530SIM_ACC_H
#define CC2530SIM_ACC_H

#include "../MemoryLocation.h"
class Acc : public MemoryLocation {
public:
    Acc() :MemoryLocation(0xE0) {

    }
public:
    virtual std::string getName() override {
        return "A";
    }
};


#endif //CC2530SIM_ACC_H
