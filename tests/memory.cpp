#include <gtest/gtest.h>

#include <yeenboy/core/memory/vram.hpp>
#include <yeenboy/core/memory/wram.hpp>

#include "yeenboy/common/defs.hpp"

TEST(Memory, BasicMemory) {
    WRAM wram;
    VRAM vram;

    wram.Write(defs::MMUAddresses::WRAM_START + 2, 42);
    EXPECT_EQ(wram.Read(defs::MMUAddresses::WRAM_START + 2), 42);

    vram.Write(defs::MMUAddresses::VRAM_START + 42, 67);
    EXPECT_EQ(vram.Read(defs::MMUAddresses::VRAM_START + 42), 67);
}

TEST(Memory, NegativeWRAM) {
    WRAM wram;
    EXPECT_ANY_THROW(wram.Write(0x2100, 1));
}

TEST(Memory, NegativeVRAM) {
    VRAM vram;
    EXPECT_ANY_THROW(vram.Write(0x3001, 1));
}