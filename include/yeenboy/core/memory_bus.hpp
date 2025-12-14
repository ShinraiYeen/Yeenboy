#pragma once

#include <stdint.h>

#include <array>

#include "yeenboy/core/memory/vram.hpp"
#include "yeenboy/core/memory/wram.hpp"

/**
 * @brief Defines the memory bus for the Gameboy.
 *
 */
class MemoryBus {
   public:
    // Constructors
    MemoryBus() = delete;
    MemoryBus(WRAM& wram, VRAM& vram) : m_wram(wram), m_vram(vram) {}

    // Destructors
    ~MemoryBus() = default;

   private:
    WRAM& m_wram;  // Work RAM
    VRAM& m_vram;  // Video RAM
};