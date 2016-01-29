//
// Created by developer on 1/29/16.
//

#ifndef CC2530SIM_DMA1CFGH_H
#define CC2530SIM_DMA1CFGH_H
#include "../MemoryLocation.h"
class DMA1CFGH : public MemoryLocation {
public:
    DMA1CFGH() :MemoryLocation(0xD3) {
    }
public:
    virtual std::string getName() override {
        return "DMA1CFGH";
    }
};
#endif //CC2530SIM_DMAIRQ_H
