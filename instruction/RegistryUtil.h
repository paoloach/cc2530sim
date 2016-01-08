//
// Created by developer on 12/11/15.
//

#ifndef CC2530SIM_REGISTRYUTIL_H
#define CC2530SIM_REGISTRYUTIL_H


#include <stdint.h>
#include "../XData.h"

class RegistryUtil {
public:
    RegistryUtil(XData & xData):xData(xData){}
public:
    uint16_t  getRAddress(uint8_t opcode);
    uint16_t  getXAddressFromBitAddress(uint8_t bitAddress);
    uint16_t  getDPH();
    uint16_t  getDPL();
private:
    XData & xData;
};


#endif //CC2530SIM_REGISTRYUTIL_H
