#pragma once

#include "yeenboy/common/types.hpp"
#include "yeenboy/core/cartridge/cartridge.hpp"
#include "yeenboy/core/cpu/cpu.hpp"
#include "yeenboy/core/memory_bus.hpp"

class System {
   public:
    System() = delete;
    explicit System(const std::filesystem::path& path);
    ~System() = default;

    void Tick(u32 m_cycles);

   private:
    Cartridge m_cartridge;
    WRAM m_wram;
    VRAM m_vram;
    IOController m_io_controller;
    MemoryBus m_mmu;
    CPU m_cpu;
};