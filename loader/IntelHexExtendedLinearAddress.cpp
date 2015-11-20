//
// Created by root on 11/16/15.
//

#include "IntelHexExtendedLinearAddress.h"
#include "../Exceptions/InvalidIntelHexFile.h"

void IntelHexExtendedLinearAddress::execute(std::vector<uint8_t> &memory) {
    if (data.size() != 2){
        throw InvalidIntelHexFile("Invalid size for hex code 4");
    }
    extendLinearAddress = (data[0]<< 8) + data[1];
}
