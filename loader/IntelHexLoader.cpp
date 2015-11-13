//
// Created by root on 11/9/15.
//

#include "IntelHexLoader.h"
#include "IntelHexLine.h
#include "IntelHexLine.h"

void IntelHexLoader::load(std::istream &in) {
    std::string line;
    std::vector<uint8_t> memory;

    while (!in.eof() && !in.fail()) {
        std::getline(in, line);
        IntelHexLine::parseLine(std::move(line))->execute(memory);
    }




}
