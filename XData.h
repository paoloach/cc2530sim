//
// Created by Paolo Achdjian on 12/1/15.
// Copyright (c) 2015  Paolo Achdjian All rights reserved.
//

#ifndef CC2530SIM_XDATA_H
#define CC2530SIM_XDATA_H

#include <vector>
#include <memory>
#include "MemoryLocation.h"
#include "Registers.h"

class XData {
public:
    XData();
    std::shared_ptr<MemoryLocation> A;
    std::shared_ptr<MemoryLocation> B;
    std::shared_ptr<MemoryLocation> status;
public:
    std::shared_ptr<MemoryLocation> & operator[](uint16_t index) {
        return data[index];
    }

    std::shared_ptr<MemoryLocation> & operator[](Data8 index) {
        return data[index.getValue()];
    }

    std::shared_ptr<MemoryLocation>  operator[](Register reg){
        return data[static_cast<uint16_t>(reg)];
    }
private:
    std::vector<std::shared_ptr<MemoryLocation>> data;
};


#endif //CC2530SIM_XDATA_H
