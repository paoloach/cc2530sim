//
// Created by developer on 1/28/16.
//

#ifndef CC2530SIM_ENCDI_H
#define CC2530SIM_ENCDI_H
#include "../MemoryLocation.h"
class ENCDI : public MemoryLocation {
public:
    ENCDI() :MemoryLocation(0xB1) {

    }
public:
    virtual std::string getName() override {
        return "ENCDI";
    }
};
#endif //CC2530SIM_ENCDI_H
