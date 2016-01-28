//
// Created by developer on 1/28/16.
//

#ifndef CC2530SIM_RNDH_H
#define CC2530SIM_RNDH_H
#include "../MemoryLocation.h"
class RNDH : public MemoryLocation {
public:
    RNDH() :MemoryLocation(0xBD) {

    }
public:
    virtual std::string getName() override {
        return "RNDH";
    }
};
#endif //CC2530SIM_RNDL_H
