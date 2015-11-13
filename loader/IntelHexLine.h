//
// Created by root on 11/9/15.
//

#ifndef CC2530_INTELHEXLINE_H
#define CC2530_INTELHEXLINE_H

#include <tuple>
#include <vector>

class IntelHexLine {
public:
    enum Type {
        Invalid,
        Data,
        EndOfFile,
        ExtendedSegmentAddress,
        StartSegmentAddress,
        ExtendedLinearAddress,
        StartLinearAddress
    };

    using Line=std::tuple<int, int, Type, std::vector<uint8_t> >;
public:
    static IntelHexLine * parseLine(std::string && line);
public:
    virtual void execute(std::vector<uint8_t> & memory)=0;
};


#endif //CC2530_INTELHEXLINE_H
