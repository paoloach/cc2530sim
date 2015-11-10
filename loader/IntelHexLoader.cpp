//
// Created by root on 11/9/15.
//

#include "IntelHexLoader.h"

void IntelHexLoader::load(std::istream &in) {
    std::string line;

    while (!in.eof() && !in.fail()) {
        std::getline(in, line);
    }




}
