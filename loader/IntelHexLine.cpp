//
// Created by root on 11/9/15.
//

#include "IntelHexLine.h"
#include "../Exceptions/InvalidIntelHexFile.h"
#include "IntelHexData.h"
#include "HexLine.h"
#include "IntelEndOfFile.h"
#include "IntelHexExtendedLinearAddress.h"

IntelHexLine * IntelHexLine::parseLine(std::string &&line, IntelHexStatus & status) {

    auto bytes = HexLine::getAsBytes(std::move(line));
    auto size = bytes[0];
    auto address = bytes[1]*256+bytes[2];
    auto startData = bytes.begin()+4;

    switch(bytes[3]){
        case 0:
            return new IntelHexData(address, status, std::vector<uint8_t>(startData, startData+size));
        case 1:
            return new IntelEndOfFile(status.finished);
        case 4:
            return new IntelHexExtendedLinearAddress(status.extendLinearAddress, std::vector<uint8_t>(startData, startData+size));
    }

    return nullptr;

}



