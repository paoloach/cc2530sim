//
// Created by root on 11/10/15.
//

#include "HexLine.h"
#include "../Exceptions/InvalidIntelHexFile.h"

std::vector<uint8_t> HexLine::getAsBytes(const std::string &line) {
    if (line.size() == 0){
        throw InvalidIntelHexFile("line too short");
    }

    if (line[0] != ':'){
        throw InvalidIntelHexFile("Invalid start header: must be ':'");
    }

    std::vector<uint8_t> result;
    int index=1;

    if ((line.size() % 2) == 0){
        throw InvalidIntelHexFile("Invalid number of hex digit: they should be even");
    }
    while (index < line.size()){
        result.push_back( stoi(line.substr(index, 2), nullptr, 16) );
        index += 2;
    }

    return result;
}
