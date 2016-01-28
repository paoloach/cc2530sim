//
// Created by developer on 1/25/16.
//

#ifndef CC2530SIM_ADCCON1_H
#define CC2530SIM_ADCCON1_H

#include "../MemoryLocation.h"
class ADCCON1 : public MemoryLocation {
public:
    ADCCON1() :MemoryLocation(0xB4) {

    }
public:
    virtual std::string getName() override {
        return "ADCCON1";
    }
};

#endif //CC2530SIM_ADCCON1_H
