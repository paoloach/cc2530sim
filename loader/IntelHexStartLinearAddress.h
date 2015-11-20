//
// Created by developer on 11/20/15.
//

#ifndef CC2530SIM_INTELHEXSTARTLINEARADDRESS_H
#define CC2530SIM_INTELHEXSTARTLINEARADDRESS_H


#include "IntelHexLine.h"

class IntelHexStartLinearAddress : public IntelHexLine {
    uint32_t & startLinearAddress;
    std::vector<uint8_t> data;
public:
    IntelHexStartLinearAddress(uint32_t & startLinearAddress,std::vector<uint8_t> &&data): startLinearAddress(startLinearAddress),data(data){};
    virtual void execute(std::vector<uint8_t> & memory) override ;
};


#endif //CC2530SIM_INTELHEXSTARTLINEARADDRESS_H
