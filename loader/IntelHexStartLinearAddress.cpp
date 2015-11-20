//
// Created by developer on 11/20/15.
//

#include <iostream>
#include <iomanip>
#include "IntelHexStartLinearAddress.h"
#include "../Exceptions/InvalidIntelHexFile.h"

void IntelHexStartLinearAddress::execute(std::vector<uint8_t> &memory) {
    if (data.size() != 4) {
        throw InvalidIntelHexFile("Invalid size for hex code 5");
    }
    startLinearAddress = (data[0] << 24) + (data[1] << 16) + (data[2] << 8) + data[3];
    std::cout << "start linear address: "  << std::hex << startLinearAddress << std::endl;
}
