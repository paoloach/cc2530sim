//
// Created by root on 11/9/15.
//

#include "IntelHexData.h"

IntelHexData::IntelHexData(const std::string &line) {

}

void IntelHexData::execute() {
    IntelHexLine::execute();
}

IntelHexData::IntelHexData(uint32_t address, std::vector<uint8_t> &&data) :address(address), data(data){


}
