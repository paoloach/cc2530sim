//
// Created by developer on 12/18/15.
//

#ifndef CC2530SIM_FMAP_H
#define CC2530SIM_FMAP_H

#include "../MemoryLocation.h"
class FMAP : public MemoryLocation {
public:
    FMAP() :MemoryLocation(0x9F) {

    }
public:
    virtual std::string getName() override {
        return "FMAP";
    }
};


#endif //CC2530SIM_FMAP_H
