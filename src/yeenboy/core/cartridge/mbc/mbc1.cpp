#include "yeenboy/core/cartridge/mbc/mbc1.hpp"

#include <stdexcept>

#include "yeenboy/common/defs.hpp"
#include "yeenboy/common/logger.hpp"
#include "yeenboy/common/utils.hpp"

MBC1::MBC1(std::vector<uint8_t>& rom, std::vector<uint8_t>& ram) : MBC(rom, ram) { Logger::Debug("Initialized MBC1"); }

uint8_t MBC1::Read(size_t addr) const {
    auto high_nibble = static_cast<uint8_t>((addr >> 12) & 0xF);
    switch (high_nibble) {
        case 0x0:
        case 0x1:
        case 0x2:
        case 0x3:
            return m_rom.at(addr);
            break;

        case 0x4:
        case 0x5:
        case 0x6:
        case 0x7:
            return m_rom.at(addr + (m_selected_rom_bank * defs::kBankSize));

        case 0xA:
        case 0xB:
            return m_ram.at(addr - defs::mmu_addresses::kExternalRamStart);
            break;

        default:
            throw std::out_of_range("MBC1 range out of bounds");
    }
}

void MBC1::Write(size_t addr, uint8_t val) {
    auto high_nibble = static_cast<uint8_t>((addr >> 12) & 0xF);
    switch (high_nibble) {
        case 0x0:
        case 0x1:
            // MBC1 RAM enable
            throw std::runtime_error("MBC1 RAM enable not implemented");
            break;

        case 0x2:
        case 0x3:
            // MB1 ROM bank select
            throw std::runtime_error("MBC1 ROM bank select not implemented");
            break;

        case 0x4:
        case 0x5:
            // MBC1 RAM bank select
            throw std::runtime_error("MBC1 RAM bank select not implemented");
            break;

        case 0x6:
        case 0x7:
            // MBC1 banking mode select
            m_banking_mode = val & 0b1 ? BankingMode::kAdvanced : BankingMode::kSimple;
            break;

        case 0xA:
        case 0xB:
            // Write to RAM
            m_ram.at(addr - defs::mmu_addresses::kExternalRamStart) = val;

        default:
            throw std::out_of_range("MBC1 range out of bounds");
    }
}