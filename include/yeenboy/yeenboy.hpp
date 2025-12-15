#pragma once

#include <filesystem>

#include "yeenboy/core/cartridge.hpp"
#include "yeenboy/core/cpu.hpp"
#include "yeenboy/core/memory_bus.hpp"

/**
 * @brief Defines the Gameboy emulator.
 *
 * This will run the emulator as soon as the object is created, and subsequently free it once it goes out of scope. This
 * class combines all of the modules of the emulator into a single system.
 *
 */
class Yeenboy {
   public:
    Yeenboy() = delete;
    Yeenboy(const std::filesystem::path& path);
    ~Yeenboy() = default;

   private:
    Cartridge m_cartridge;
    WRAM m_wram;
    VRAM m_vram;
    MemoryBus m_mmu;
    CPU m_cpu;
};