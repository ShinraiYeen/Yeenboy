#pragma once

#include <array>

#include "yeenboy/core/mmu_module.hpp"

class WRAM : public MMUModule {
   public:
    static constexpr size_t WRAM_SIZE = 0x2000;  // 8Kb

    WRAM();
    ~WRAM() = default;

    uint8_t Read(size_t addr) const override;
    void Write(size_t addr, uint8_t val) override;

   private:
    std::array<uint8_t, WRAM_SIZE> m_data;
};