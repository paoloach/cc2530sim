//
// Created by root on 11/6/15.
//

#include <string>
#include "FlashMemory.h"
#include "loader/IntelHexLoader.h"

void FlashMemory::loafFromString(std::istream &stream) {
    IntelHexLoader::load(stream, memory);
}
