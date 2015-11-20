//
// Created by root on 11/16/15.
//

#include "gtest/gtest.h"

#include "../../loader/IntelEndOfFile.h"

TEST(IntelEndOfFile, simpleCase){
    std::vector<uint8_t > memory;
    IntelHexLine::IntelHexStatus status;
    IntelHexLine * intelHexLine = IntelHexLine::parseLine(std::string(":00000001C7"),status);
    ASSERT_NE(intelHexLine, nullptr);
    IntelEndOfFile *intelEndOfFile = dynamic_cast<IntelEndOfFile *>(intelHexLine);
    ASSERT_NE(intelEndOfFile, nullptr);

    intelEndOfFile->execute(memory);
    ASSERT_TRUE(status.finished);
}