#include <gtest/gtest.h>

#include <yeenboy/core/memory/vram.hpp>
#include <yeenboy/core/memory/wram.hpp>

TEST(Memory, BasicMemory) {
    WRAM wram;
    VRAM vram;

    EXPECT_EQ(wram.Size(), 8192);
    EXPECT_EQ(vram.Size(), 8192);

    wram[0] = 42;
    EXPECT_EQ(wram[0], 42);

    vram[42] = 67;
    EXPECT_EQ(vram[42], 67);
}