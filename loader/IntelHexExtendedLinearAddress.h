//
// Created by root on 11/16/15.
//

#ifndef CC2530SIM_INTELHEXEXTENDEDLINEARADDRESS_H
#define CC2530SIM_INTELHEXEXTENDEDLINEARADDRESS_H


#include "IntelHexLine.h"

class IntelHexExtendedLinearAddress : public IntelHexLine {
    uint16_t & extendLinearAddress;
    std::vector<uint8_t> data;

public:
    IntelHexExtendedLinearAddress(uint16_t & extendLinearAddress,std::vector<uint8_t> &&data): extendLinearAddress(extendLinearAddress),data(data){};
    virtual void execute(std::vector<uint8_t> & memory) override ;

};


#endif //CC2530SIM_INTELHEXEXTENDEDLINEARADDRESS_H
