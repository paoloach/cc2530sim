//
// Created by developer on 1/25/16.
//

#ifndef CC2530SIM_ADCCON3_H
#define CC2530SIM_ADCCON3_H
#include "../MemoryLocation.h"
class ADCCON3 : public MemoryLocation {
public:
    ADCCON3() :MemoryLocation(0xB6) {

    }
public:
    virtual std::string getName() override {
        return "ADCCON3";
    }
};
#endif //CC2530SIM_ADCCON3_H
