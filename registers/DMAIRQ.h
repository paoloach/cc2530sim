//
// Created by developer on 1/29/16.
//

#ifndef CC2530SIM_DMAIRQ_H
#define CC2530SIM_DMAIRQ_H
#include "../MemoryLocation.h"
class DMAIRQ : public MemoryLocation {
public:
    DMAIRQ() :MemoryLocation(0xD1) {
    }
public:
    virtual std::string getName() override {
        return "DMAIRQ";
    }
};
#endif //CC2530SIM_DMAIRQ_H
