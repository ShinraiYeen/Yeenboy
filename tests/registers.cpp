#include <gtest/gtest.h>

#include <yeenboy/core/register.hpp>

TEST(Register, BasicByteRegister) {
    Register<uint8_t> reg;
    EXPECT_EQ(reg.Value(), 0);
    EXPECT_EQ(reg.BitWidth(), 8);
    reg.Set(42);
    EXPECT_EQ(reg.Value(), 42);
}

TEST(Register, BasicPairRegister) {
    Register<uint8_t> a;
    Register<uint8_t> b;
    PairRegister reg(a, b);

    EXPECT_EQ(reg.Value(), 0);

    a.Set(0x01);
    b.Set(0x02);

    EXPECT_EQ(reg.Value(), 0x0102);

    reg.Set(0xDDFF);
    EXPECT_EQ(reg.Value(), 0xDDFF);

    EXPECT_EQ(a.Value(), 0xDD);
    EXPECT_EQ(b.Value(), 0xFF);
}

TEST(Register, BasicFlagRegister) {
    FlagRegister reg;
    EXPECT_EQ(reg.Value(), 0);
}