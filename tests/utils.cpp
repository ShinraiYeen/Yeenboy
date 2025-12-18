#include <gtest/gtest.h>

#include <yeenboy/common/utils.hpp>

TEST(Utils, BasicBitwise) {
    EXPECT_TRUE(util::CheckBit(0x01, 0));
    EXPECT_FALSE(util::CheckBit(0x01, 1));
    EXPECT_EQ(util::SetBitTo(0, 1, true), 0b00000010);
    EXPECT_EQ(util::SetBitTo(~0, 1, false), 0b11111101);
    EXPECT_EQ(util::ExtractHigh(0xFFDD), 0xFF);
    EXPECT_EQ(util::ExtractLow(0xFFDD), 0xDD);
    EXPECT_EQ(util::CombineBytes(0xDD, 0xFF), 0xDDFF);
}