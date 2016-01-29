//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_RFD1_H
#define CC2530SIM_RFD1_H

#include "../MemoryLocation.h"
class RFD : public MemoryLocation {
public:
    RFD() :MemoryLocation(0xD9) {

    }
public:
    virtual std::string getName() override {
        return "RFD";
    }
};

#endif //CC2530SIM_P0_H
