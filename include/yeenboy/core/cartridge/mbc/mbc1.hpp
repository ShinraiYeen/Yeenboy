#pragma once

#include "yeenboy/core/cartridge/mbc/mbc.hpp"

class MBC1 final : public MBC {
   public:
    enum class BankingMode {
        SIMPLE,
        ADVANCED,
    };

    MBC1(std::vector<uint8_t>& rom, std::vector<uint8_t>& ram);
    ~MBC1() = default;

    uint8_t ReadRom(size_t addr) const override;
    uint8_t ReadRam(size_t addr) const override;

    void WriteRom(size_t addr, uint8_t val) override;
    void WriteRam(size_t addr, uint8_t val) override;

   private:
    uint8_t m_selected_rom_bank = 0;
    bool m_ram_enable = 0;
    uint8_t m_selected_ram_bank = 0;
    BankingMode m_banking_mode = BankingMode::SIMPLE;
};