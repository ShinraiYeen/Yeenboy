#pragma once

#include <array>

#include "yeenboy/common/types.hpp"
#include "yeenboy/core/mmu_module.hpp"

class VRAM final : public MMUModule {
   public:
    static constexpr size_t kVramSize = 0x2000;  // 8Kb

    VRAM();
    ~VRAM() override = default;

    u8 Read(size_t addr) const override;
    void Write(size_t addr, u8 val) override;

   private:
    std::array<u8, kVramSize> m_data;
};