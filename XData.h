//
// Created by Paolo Achdjian on 12/1/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#ifndef CC2530SIM_XDATA_H
#define CC2530SIM_XDATA_H

#include <vector>
#include "MemoryLocation.h"
#include "Registers.h"

class XData {
public:
    XData();
public:
    MemoryLocation & operator[](uint16_t index) {
        return data[index];
    }

    MemoryLocation & operator[](Register reg){
        return data[static_cast<uint16_t>(reg)];
    }
private:
    std::vector<MemoryLocation> data;
};


#endif //CC2530SIM_XDATA_H
