//
// Created by developer on 1/29/16.
//

#ifndef CC2530SIM_DMA1CFGL_H
#define CC2530SIM_DMA1CFGL_H
#include "../MemoryLocation.h"
class DMA1CFGL : public MemoryLocation {
public:
    DMA1CFGL() :MemoryLocation(0xD2) {
    }
public:
    virtual std::string getName() override {
        return "DMA1CFGL";
    }
};
#endif //CC2530SIM_DMAIRQ_H
