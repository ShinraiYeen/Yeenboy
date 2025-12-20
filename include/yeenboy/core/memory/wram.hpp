#pragma once

#include <array>

#include "yeenboy/common/types.hpp"
#include "yeenboy/core/mmu_module.hpp"

class WRAM final : public MMUModule {
   public:
    static constexpr size_t kWramSize = 0x2000;  // 8Kb

    WRAM();
    ~WRAM() override = default;

    u8 Read(size_t addr) const override;
    void Write(size_t addr, u8 val) override;

   private:
    std::array<u8, kWramSize> m_data;
};