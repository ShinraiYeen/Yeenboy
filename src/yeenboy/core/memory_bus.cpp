#include "yeenboy/core/memory_bus.hpp"

#include <stdexcept>

#include "yeenboy/common/logger.hpp"
#include "yeenboy/core/cartridge/cartridge.hpp"

MemoryBus::MemoryBus(WRAM& wram, VRAM& vram, Cartridge& cartridge)
    : m_wram(wram), m_vram(vram), m_cartridge(cartridge) {
    Logger::Debug("Memory bus initialized");
}

uint8_t MemoryBus::Read(size_t addr) {
    size_t high_nibble = (addr >> 12) & 0xF;

    switch (high_nibble) {
        case 0x0:
        case 0x1:
        case 0x2:
        case 0x3:
        case 0x4:
        case 0x5:
        case 0x6:
        case 0x7:
            return m_cartridge.ReadRom(addr - MMUAddresses::ROM_BANK_NN_START);

        case 0xA:
        case 0xB:
            return m_cartridge.ReadRam(addr - MMUAddresses::EXTERNAL_RAM_START);

        case 0x8:
        case 0x9:
            return m_vram.Read(addr - MMUAddresses::VRAM_START);

        case 0xC:
        case 0xD:
            return m_wram.Read(addr - MMUAddresses::WRAM_START);

        default:
            // TODO: Handle other cases here
            throw std::runtime_error("Attempted to read from unimplemented memory address: " + std::to_string(addr));
            break;
    }
}

void MemoryBus::Write(size_t addr, uint8_t val) {
    size_t high_nibble = (addr >> 12) & 0xF;

    switch (high_nibble) {
        case 0x0:
        case 0x1:
        case 0x2:
        case 0x3:
        case 0x4:
        case 0x5:
        case 0x6:
        case 0x7:
            m_cartridge.WriteRom(addr - MMUAddresses::ROM_BANK_NN_START, val);
            break;

        case 0xA:
        case 0xB:
            m_cartridge.WriteRam(addr - MMUAddresses::EXTERNAL_RAM_START, val);
            break;

        case 0x8:
        case 0x9:
            m_vram.Write(addr - MMUAddresses::VRAM_START, val);
            break;

        case 0xC:
        case 0xD:
            m_wram.Write(addr - MMUAddresses::WRAM_START, val);
            break;

        default:
            // TODO: Handle other cases here
            throw std::runtime_error("Attempted to read from unimplemented memory address: " + std::to_string(addr));
            break;
    }
}