#pragma once

#include <stdint.h>

#include "yeenboy/core/cartridge/cartridge.hpp"
#include "yeenboy/core/io_controller.hpp"
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
    MemoryBus(WRAM& wram, VRAM& vram, Cartridge& cartridge, IOController& io_controller);

    // Destructors
    ~MemoryBus() = default;

    uint8_t Read(size_t addr);
    void Write(size_t addr, uint8_t val);

   private:
    WRAM& m_wram;            // Work RAM
    VRAM& m_vram;            // Video RAM
    Cartridge& m_cartridge;  // Cartridge
    IOController& m_io_controller;
};