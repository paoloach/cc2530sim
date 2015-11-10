//
// Created by root on 11/9/15.
//

#include "IntelHexLine.h"
#include "../Exceptions/InvalidIntelHexFile.h"
#include "IntelHexData.h"

IntelHexLine * IntelHexLine::parseLine(const std::string &line) {
    char buffer[10];

    if (line.size() < 8){
        throw InvalidIntelHexFile("line too short");
    }
    if (line[0] != ':'){
        throw InvalidIntelHexFile("line must begin with : but begin with "+ line[0]);
    }

    uint32_t dataLen = std::stoi(line.substr(1,2), nullptr,16);
    uint32_t address = std::stoi(line.substr(3,4), nullptr,16);
    if (line.size() <  9 + dataLen+2){
        throw InvalidIntelHexFile("line too short");
    }

    switch (decodeType(line.substr(7,2))){
        case Data:
            return new IntelHexData(address, getData(line, dataLen));
    }

    return nullptr;

}

std::vector<uint8_t> IntelHexLine::getData(const std::string &line, uint32_t dataLen) {
    std::vector<uint8_t > data;
    for(int i=0; i < dataLen; i++){
        data.push_back(stoi(line.substr(11 + i * 2, 2), nullptr, 16));
    }
    return data;
}

void IntelHexLine::execute() {

}

IntelHexLine::Type IntelHexLine::decodeType(const std::string &type) {
    if (type == "00"){
        return Data;
    }
    if (type == "01"){
        return EndOfFile;
    }

    if (type == "02"){
        return ExtendedSegmentAddress;
    }
    if (type == "03"){
        return StartSegmentAddress;
    }
    if (type == "04"){
        return ExtendedLinearAddress;
    }
    if (type == "05"){
        return StartLinearAddress;
    }
    throw InvalidIntelHexFile("Invalid type "+ type);
}
