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
    static IntelHexLine * parseLine(const std::string & line);
public:
    virtual void execute();
private:
    static Type decodeType(const std::string & type);

};


#endif //CC2530_INTELHEXLINE_H
