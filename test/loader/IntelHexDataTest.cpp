//
// Created by root on 11/13/15.
//

#include "gtest/gtest.h"

#include "../../loader/IntelHexData.h"

TEST(IntelHexData, simpleCase){
    std::vector<uint8_t > memory;
    IntelHexLine::IntelHexStatus status;

    IntelHexLine * intelHexLine = IntelHexLine::parseLine(std::string(":100130003F0156702B5E712B722B732146013421C7"),status);
    ASSERT_NE(intelHexLine, nullptr);
    IntelHexData * intelHexData = dynamic_cast<IntelHexData *>(intelHexLine);
    ASSERT_NE(intelHexData, nullptr);

    intelHexData->execute(memory);
    ASSERT_EQ(0x140,memory.size() );
    ASSERT_EQ(0x3F,memory[0x130] );
    ASSERT_EQ(0x72,memory[0x138] );
    ASSERT_EQ(0x21,memory[0x13F] );
}