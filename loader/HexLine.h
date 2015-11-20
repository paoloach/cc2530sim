//
// Created by root on 11/10/15.
//

#ifndef CC2530_HEXLINE_H
#define CC2530_HEXLINE_H

#include <vector>
#include <string>
#include <stdint.h>

class HexLine {
public:

    static std::vector<uint8_t> getAsBytes(const std::string & line);
};


#endif //CC2530_HEXLINE_H
