//
// Created by root on 11/9/15.
//

#ifndef CC2530_INTELHEXDATA_H
#define CC2530_INTELHEXDATA_H


#include <string>
#include "IntelHexLine.h"

class IntelHexData : public IntelHexLine {
private:
    std::vector<uint8_t> data;
    uint32_t address;
    IntelHexStatus & status;
public:
    IntelHexData(uint32_t address, IntelHexStatus & status, std::vector<uint8_t> &&vector);

    virtual void execute(std::vector<uint8_t> & memory) override ;
};


#endif //CC2530_INTELHEXDATA_H
