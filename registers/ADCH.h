//
// Created by developer on 1/28/16.
//

#ifndef CC2530SIM_ADCH_H
#define CC2530SIM_ADCH_H
#include "../MemoryLocation.h"
class ADCH : public MemoryLocation {
public:
    ADCH() :MemoryLocation(0xBB) {

    }
public:
    virtual std::string getName() override {
        return "ADCH";
    }
};
#endif //CC2530SIM_ADCL_H
