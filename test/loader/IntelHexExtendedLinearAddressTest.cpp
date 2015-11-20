//
// Created by root on 11/16/15.
//
#include "gtest/gtest.h"

#include "../../loader/IntelHexExtendedLinearAddress.h"

TEST(IntelHexExtendedLinearAddressTest, simpleCase) {
    std::vector<uint8_t> memory;
    IntelHexLine::IntelHexStatus status;

    IntelHexLine::parseLine(std::string(":100130003F0156702B5E712B722B732146013421C7"),status)->execute(memory);
    IntelHexLine *intelHexLine = IntelHexLine::parseLine(std::string(":020000040102C7"), status);
    ASSERT_NE(intelHexLine, nullptr);
    IntelHexExtendedLinearAddress *intelHexData = dynamic_cast<IntelHexExtendedLinearAddress *>(intelHexLine);
    ASSERT_NE(intelHexData, nullptr);
    intelHexData->execute(memory);

    IntelHexLine::parseLine(std::string(":100130003E0156702B5E712B732B732146013422C7"),status)->execute(memory);

    ASSERT_EQ(0x01020140, memory.size());
    ASSERT_EQ(0x3E, memory[0x01020130]);
    ASSERT_EQ(0x73, memory[0x01020138]);
    ASSERT_EQ(0x22, memory[0x0102013F]);
}