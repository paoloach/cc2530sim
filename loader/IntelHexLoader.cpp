//
// Created by root on 11/9/15.
//

#include <boost/algorithm/string.hpp>
#include "IntelHexLoader.h"
#include "IntelHexLine.h"

using namespace boost::algorithm;

void IntelHexLoader::load(std::istream &in, std::vector<uint8_t> &memory) {
    std::string line;
    IntelHexLine::IntelHexStatus status;

    while (!in.eof() && !in.fail() && !status.finished) {
        std::getline(in, line);
        if (in.fail() || in.eof()) {
            break;
        }

        trim_right(line);
        IntelHexLine::parseLine(std::move(line), status)->execute(memory);
    }

}
