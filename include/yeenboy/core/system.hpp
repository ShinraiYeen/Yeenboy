#pragma once

#include "yeenboy/common/types.hpp"
#include "yeenboy/core/cartridge/cartridge.hpp"
#include "yeenboy/core/cpu/cpu.hpp"
#include "yeenboy/core/memory_bus.hpp"
#include "yeenboy/core/timer.hpp"

class System {
   public:
    System() = delete;
    explicit System(const std::filesystem::path& path);
    ~System() = default;

    void Tick(u32 m_cycles);

   private:
    Timer m_timer;
    Cartridge m_cartridge;
    WRAM m_wram;
    VRAM m_vram;
    IOController m_io_controller;
    MemoryBus m_mmu;
    CPU m_cpu;
};