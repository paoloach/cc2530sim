//
// Created by root on 11/12/15.
//

#include "gtest/gtest.h"

#include "../../loader/HexLine.h"
#include "../../Exceptions/InvalidIntelHexFile.h"

TEST(HexLine, simpleCase){
    auto result = HexLine::getAsBytes(":00010203");

    ASSERT_EQ(0, result[0]);
    ASSERT_EQ(1, result[1]);
    ASSERT_EQ(2, result[2]);
}

TEST(HexLine, simpleHexCase){
    auto result = HexLine::getAsBytes(":AAABACFF");

    ASSERT_EQ(4, result.size());
    ASSERT_EQ(0xAA, result[0]);
    ASSERT_EQ(0xAB, result[1]);
    ASSERT_EQ(0xAC, result[2]);
    ASSERT_EQ(0xFF, result[3]);
}

TEST(HexLine, InvalidHader){
    ASSERT_THROW(HexLine::getAsBytes("AAABACFF"), InvalidIntelHexFile);
}

TEST(HexLine, OddFigure){
    ASSERT_THROW(HexLine::getAsBytes(":AAABACFF3"), InvalidIntelHexFile);
}