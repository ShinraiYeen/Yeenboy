#pragma once

#include <array>

#include "yeenboy/core/mmu_module.hpp"

class VRAM : public MMUModule {
   public:
    static constexpr size_t VRAM_SIZE = 0x2000;  // 8Kb

    VRAM();
    ~VRAM() = default;

    uint8_t Read(size_t addr) const override;
    void Write(size_t addr, uint8_t val) override;

   private:
    std::array<uint8_t, VRAM_SIZE> m_data;
};