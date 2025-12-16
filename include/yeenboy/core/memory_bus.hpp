#pragma once

#include <stdint.h>

#include "yeenboy/core/cartridge/cartridge.hpp"
#include "yeenboy/core/memory/vram.hpp"
#include "yeenboy/core/memory/wram.hpp"

namespace MMUAddresses {
static constexpr size_t ROM_BANK_00_START = 0x0000;
static constexpr size_t ROM_BANK_00_END = 0x3FFF;
static constexpr size_t ROM_BANK_NN_START = 0x4000;
static constexpr size_t ROM_BANK_NN_END = 0x7FFF;
static constexpr size_t VRAM_START = 0x8000;
static constexpr size_t VRAM_END = 0x9FFF;
static constexpr size_t EXTERNAL_RAM_START = 0xA000;
static constexpr size_t EXTERNAL_RAM_END = 0xBFFF;
static constexpr size_t WRAM_START = 0xC000;
static constexpr size_t WRAM_END = 0xDFFF;
static constexpr size_t ECHO_RAM_START = 0xE000;
static constexpr size_t ECHO_RAM_END = 0xFDFF;
static constexpr size_t OAM_START = 0xFE00;
static constexpr size_t OAM_END = 0xFE9F;
static constexpr size_t UNUSABLE_START = 0xFEA0;
static constexpr size_t UNUSABLE_END = 0xFEFF;
static constexpr size_t IO_REGISTER_START = 0xFF00;
static constexpr size_t IO_REGISTER_END = 0xFF7F;
static constexpr size_t HIGH_RAM_START = 0xFF80;
static constexpr size_t HIGH_RAM_END = 0xFFFE;
static constexpr size_t INTERRUPT_ENABLE = 0xFFFF;
}  // namespace MMUAddresses

/**
 * @brief Defines the memory bus for the Gameboy.
 *
 */
class MemoryBus {
   public:
    // Constructors
    MemoryBus() = delete;
    MemoryBus(WRAM& wram, VRAM& vram, Cartridge& cartridge);

    // Destructors
    ~MemoryBus() = default;

    uint8_t Read(size_t addr);
    void Write(size_t addr, uint8_t val);

   private:
    WRAM& m_wram;            // Work RAM
    VRAM& m_vram;            // Video RAM
    Cartridge& m_cartridge;  // Cartridge
};