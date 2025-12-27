#pragma once

#include <filesystem>

#include "yeenboy/core/system.hpp"

/**
 * @brief Defines the Gameboy emulator.
 *
 * This will run the emulator as soon as the object is created, and subsequently free it once it goes out of scope. This
 * class combines all of the modules of the emulator into a single system.
 *
 */

// m_cartridge(path), m_mmu(m_wram, m_vram, m_cartridge, m_io_controller), m_cpu(m_mmu)
class Yeenboy {
   public:
    Yeenboy() = delete;
    explicit Yeenboy(const std::filesystem::path& path);
    ~Yeenboy() = default;

   private:
    System m_system;
};