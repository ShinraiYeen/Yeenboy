#pragma once

#include "yeenboy/core/cartridge/mbc/mbc.hpp"

class MBC1 final : public MBC {
   public:
    enum class BankingMode {
        kSimple,
        kAdvanced,
    };

    MBC1(std::vector<u8>& rom, std::vector<u8>& ram);
    ~MBC1() = default;

    u8 Read(size_t addr) const override;
    void Write(size_t addr, u8 val) override;

   private:
    u8 m_selected_rom_bank = 0;
    bool m_ram_enable = false;
    u8 m_selected_ram_bank = 0;
    BankingMode m_banking_mode = BankingMode::kSimple;
};