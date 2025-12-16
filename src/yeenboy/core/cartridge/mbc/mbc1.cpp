#include "yeenboy/core/cartridge/mbc/mbc1.hpp"

#include <stdexcept>

#include "yeenboy/common/defs.hpp"
#include "yeenboy/common/logger.hpp"
#include "yeenboy/common/utils.hpp"

MBC1::MBC1(std::vector<uint8_t>& rom, std::vector<uint8_t>& ram) : MBC(rom, ram) { Logger::Debug("Initialized MBC1"); }

uint8_t MBC1::ReadRom(size_t addr) const {
    if (RANGE(addr, 0x0000, 0x3FFF)) {
        // Memory in this range is fixed
        return m_rom.at(addr);
    }

    else if (RANGE(addr, 0x4000, 0x7FFF)) {
        // Read banked rom memory
        return m_rom.at(addr + (m_selected_rom_bank * defs::BANK_SIZE));
    }

    throw std::runtime_error("[MBC1]: Attempted to read from illegal address");
}

uint8_t MBC1::ReadRam(size_t addr) const { return m_ram.at(addr); }

void MBC1::WriteRom(size_t addr, uint8_t val) {
    if (RANGE(addr, 0x0000, 0x1FFF)) {
        // MBC1 RAM enable
    }

    else if (RANGE(addr, 0x2000, 0x3FFF)) {
        // MB1 ROM bank select
    }

    else if (RANGE(addr, 0x4000, 0x5FFF)) {
        // MBC1 RAM bank select
    }

    else if (RANGE(addr, 0x6000, 0x7FFF)) {
        // MBC1 banking mode select
        m_banking_mode = val & 0b1 ? BankingMode::ADVANCED : BankingMode::SIMPLE;
    }
}

void MBC1::WriteRam(size_t addr, uint8_t val) {}