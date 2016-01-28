//
// Created by developer on 1/28/16.
//

#ifndef CC2530SIM_IRCON_H
#define CC2530SIM_IRCON_H

#include "../MemoryLocation.h"
class IRCON : public MemoryLocation {
public:
    IRCON() :MemoryLocation(0xC0) {
    }
public:
    virtual std::string getName() override {
        return "IRCON";
    }
};


#endif //CC2530SIM_IRCON_H
