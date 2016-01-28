//
// Created by developer on 1/28/16.
//

#ifndef CC2530SIM_ADCL_H
#define CC2530SIM_ADCL_H
#include "../MemoryLocation.h"
class ADCL : public MemoryLocation {
public:
    ADCL() :MemoryLocation(0xBA) {

    }
public:
    virtual std::string getName() override {
        return "ADCL";
    }
};
#endif //CC2530SIM_ADCL_H
