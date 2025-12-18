#pragma once

#include "yeenboy/core/cartridge/mbc/mbc.hpp"

class MBC1 final : public MBC {
   public:
    enum class BankingMode {
        kSimple,
        kAdvanced,
    };

    MBC1(std::vector<uint8_t>& rom, std::vector<uint8_t>& ram);
    ~MBC1() = default;

    uint8_t Read(size_t addr) const override;
    void Write(size_t addr, uint8_t val) override;

   private:
    uint8_t m_selected_rom_bank = 0;
    bool m_ram_enable = false;
    uint8_t m_selected_ram_bank = 0;
    BankingMode m_banking_mode = BankingMode::kSimple;
};