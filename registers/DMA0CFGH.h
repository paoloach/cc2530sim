//
// Created by developer on 1/29/16.
//

#ifndef CC2530SIM_DMA0CFGH_H
#define CC2530SIM_DMA0CFGH_H
#include "../MemoryLocation.h"
class DMA0CFGH : public MemoryLocation {
public:
    DMA0CFGH() :MemoryLocation(0xD5) {
    }
public:
    virtual std::string getName() override {
        return "DMA0CFGH";
    }
};
#endif //CC2530SIM_DMAIRQ_H
