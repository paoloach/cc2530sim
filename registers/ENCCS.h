//
// Created by developer on 1/28/16.
//

#ifndef CC2530SIM_ENCCS_H
#define CC2530SIM_ENCCS_H
#include "../MemoryLocation.h"
class ENCCS : public MemoryLocation {
public:
    ENCCS() :MemoryLocation(0xB3) {

    }
public:
    virtual std::string getName() override {
        return "ENCCS";
    }
};
#endif //CC2530SIM_ENCDI_H
