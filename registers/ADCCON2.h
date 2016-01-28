//
// Created by developer on 1/25/16.
//

#ifndef CC2530SIM_ADCCON2_H
#define CC2530SIM_ADCCON2_H
#include "../MemoryLocation.h"
class ADCCON2 : public MemoryLocation {
public:
    ADCCON2() :MemoryLocation(0xB5) {

    }
public:
    virtual std::string getName() override {
        return "ADCCON2";
    }
};
#endif //CC2530SIM_ADCCON2_H
