#pragma once

#include <array>

#include "yeenboy/core/mmu_module.hpp"

class VRAM final : public MMUModule {
   public:
    static constexpr size_t kVramSize = 0x2000;  // 8Kb

    VRAM();
    ~VRAM() override = default;

    uint8_t Read(size_t addr) const override;
    void Write(size_t addr, uint8_t val) override;

   private:
    std::array<uint8_t, kVramSize> m_data;
};