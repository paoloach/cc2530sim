//
// Created by root on 11/9/15.
//

#ifndef CC2530_INTELHEXLOADER_H
#define CC2530_INTELHEXLOADER_H

#include <vector>
#include <istream>


class IntelHexLoader {
public:

    void static load(std::istream & in,std::vector<uint8_t> & memory);


};


#endif //CC2530_INTELHEXLOADER_H
