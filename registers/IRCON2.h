//
// Created by developer on 1/28/16.
//

#ifndef CC2530SIM_IRCON2_H
#define CC2530SIM_IRCON2_H

#include "../MemoryLocation.h"
class IRCON2 : public MemoryLocation {
public:
    IRCON2() :MemoryLocation(0xE8) {
    }
public:
    virtual std::string getName() override {
        return "IRCON2";
    }
};


#endif //CC2530SIM_IRCON_H
