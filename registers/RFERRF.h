//
// Created by developer on 1/7/16.
//

#ifndef CC2530SIM_ERRF_H
#define CC2530SIM_ERRF_H

#include "../MemoryLocation.h"
class RFERRF : public MemoryLocation {
public:
    RFERRF() :MemoryLocation(0xBF) {

    }
public:
    virtual std::string getName() override {
        return "RFERRF";
    }
};

#endif //CC2530SIM_P0_H
