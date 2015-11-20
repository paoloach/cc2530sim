//
// Created by root on 11/16/15.
//

#ifndef CC2530SIM_INTELENDOFFILE_H
#define CC2530SIM_INTELENDOFFILE_H


#include "IntelHexLine.h"

class IntelEndOfFile : public IntelHexLine {
private:
    bool &finished;
public:
    IntelEndOfFile(bool &finished): finished(finished) {};
    virtual void execute(std::vector<uint8_t> & memory) override ;
};


#endif //CC2530SIM_INTELENDOFFILE_H
