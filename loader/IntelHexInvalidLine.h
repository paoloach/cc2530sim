//
// Created by developer on 11/20/15.
//

#ifndef CC2530SIM_INTELHEXINVALIDLINE_H
#define CC2530SIM_INTELHEXINVALIDLINE_H

#include "IntelHexLine.h"

class IntelHexInvalidLine : public IntelHexLine {
public:
    std::string line;
public:
    IntelHexInvalidLine(const std::string &line):line(line){}
    virtual void execute(std::vector<uint8_t> & memory) override ;
};


#endif //CC2530SIM_INTELHEXINVALIDLINE_H
