#include "yeenboy/core/cartridge/mbc/mbc1.hpp"

#include <stdexcept>

#include "yeenboy/common/defs.hpp"
#include "yeenboy/common/logger.hpp"
#include "yeenboy/common/utils.hpp"

MBC1::MBC1(std::vector<uint8_t>& rom, std::vector<uint8_t>& ram) : MBC(rom, ram) { Logger::Debug("Initialized MBC1"); }

uint8_t MBC1::Read(size_t addr) const {
    if (addr <= 0x3FFF) {
        // Memory in this range is fixed
        return m_rom.at(addr);
    }

    else if (RANGE(addr, 0x4000, 0x7FFF)) {
        // Read banked rom memory
        return m_rom.at(addr + (m_selected_rom_bank * defs::BANK_SIZE));
    }

    else if (RANGE(addr, 0xA000, 0xBFFF)) {
        // Read RAM
        return m_ram.at(addr - 0xA000);
    }

    throw std::out_of_range("MBC1 range out of bounds");
}

void MBC1::Write(size_t addr, uint8_t val) {
    if (addr <= 0x1FFF) {
        // MBC1 RAM enable
        throw std::runtime_error("MBC1 RAM enable not implemented");
    }

    else if (RANGE(addr, 0x2000, 0x3FFF)) {
        // MB1 ROM bank select
        throw std::runtime_error("MBC1 ROM bank select not implemented");
    }

    else if (RANGE(addr, 0x4000, 0x5FFF)) {
        // MBC1 RAM bank select
        throw std::runtime_error("MBC1 RAM bank select not implemented");
    }

    else if (RANGE(addr, 0x6000, 0x7FFF)) {
        // MBC1 banking mode select
        m_banking_mode = val & 0b1 ? BankingMode::ADVANCED : BankingMode::SIMPLE;
    }

    else if (RANGE(addr, 0xA000, 0xBFFF)) {
        // Write to RAM
        m_ram.at(addr - 0xA000) = val;
    }

    else {
        throw std::out_of_range("Address out of MBC1 range");
    }
}