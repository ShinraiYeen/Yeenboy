#include <gtest/gtest.h>

#include <yeenboy/core/memory/vram.hpp>
#include <yeenboy/core/memory/wram.hpp>

TEST(Memory, BasicMemory) {
    WRAM wram;
    VRAM vram;

    wram.Write(0, 42);
    EXPECT_EQ(wram.Read(0), 42);

    vram.Write(42, 67);
    EXPECT_EQ(vram.Read(42), 67);
}

TEST(Memory, NegativeWRAM) {
    WRAM wram;
    EXPECT_ANY_THROW(wram.Write(0x2100, 1));
}

TEST(Memory, NegativeVRAM) {
    VRAM vram;
    EXPECT_ANY_THROW(vram.Write(0x3001, 1));
}