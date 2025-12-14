#include <gtest/gtest.h>

#include <yeenboy/common/utils.hpp>

TEST(Utils, Bitwise) {
    EXPECT_TRUE(util::CheckBit(0x01, 0));
    EXPECT_FALSE(util::CheckBit(0x01, 1));
    EXPECT_EQ(util::SetBitTo(0, 1, true), 0b00000010);
    EXPECT_EQ(util::SetBitTo(~0, 1, false), 0b11111101);
}