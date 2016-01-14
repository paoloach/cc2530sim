//
// Created by developer on 1/14/16.
//

#ifndef CC2530SIM_T1STAT_H
#define CC2530SIM_T1STAT_H


#include "../MemoryLocation.h"
class T1STAT : public MemoryLocation {
public:
    T1STAT() :MemoryLocation(0xAF) {
    }
public:
    virtual std::string getName() override {
        return "T1STAT";
    }
};


#endif //CC2530SIM_T1STAT_H
