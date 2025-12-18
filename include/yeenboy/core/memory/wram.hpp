#pragma once

#include <array>

#include "yeenboy/core/mmu_module.hpp"

class WRAM final : public MMUModule {
   public:
    static constexpr size_t kWramSize = 0x2000;  // 8Kb

    WRAM();
    ~WRAM() override = default;

    uint8_t Read(size_t addr) const override;
    void Write(size_t addr, uint8_t val) override;

   private:
    std::array<uint8_t, kWramSize> m_data;
};