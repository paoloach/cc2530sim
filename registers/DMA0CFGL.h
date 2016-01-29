//
// Created by developer on 1/29/16.
//

#ifndef CC2530SIM_DMA0CFGL_H
#define CC2530SIM_DMA0CFGL_H
#include "../MemoryLocation.h"
class DMA0CFGL : public MemoryLocation {
public:
    DMA0CFGL() :MemoryLocation(0xD4) {
    }
public:
    virtual std::string getName() override {
        return "DMA0CFGL";
    }
};
#endif //CC2530SIM_DMAIRQ_H
