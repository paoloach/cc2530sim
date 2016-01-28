//
// Created by developer on 1/28/16.
//

#ifndef CC2530SIM_RNDL_H
#define CC2530SIM_RNDL_H
#include "../MemoryLocation.h"
class RNDL : public MemoryLocation {
public:
    RNDL() :MemoryLocation(0xBC) {

    }
public:
    virtual std::string getName() override {
        return "RNDL";
    }
};
#endif //CC2530SIM_RNDL_H
