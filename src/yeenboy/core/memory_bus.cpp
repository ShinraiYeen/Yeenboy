#include "yeenboy/core/memory_bus.hpp"

#include <stdexcept>

#include "yeenboy/common/defs.hpp"
#include "yeenboy/common/logger.hpp"
#include "yeenboy/common/utils.hpp"
#include "yeenboy/core/cartridge/cartridge.hpp"
#include "yeenboy/core/io_controller.hpp"

MemoryBus::MemoryBus(WRAM& wram, VRAM& vram, Cartridge& cartridge, IOController& io_controller)
    : m_wram(wram), m_vram(vram), m_cartridge(cartridge), m_io_controller(io_controller) {
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
        case 0xA:
        case 0xB:
            return m_cartridge.Read(addr);

        case 0x8:
        case 0x9:
            return m_vram.Read(addr);

        case 0xC:
        case 0xD:
            return m_wram.Read(addr);

        default:
            if (RANGE(addr, defs::MMUAddresses::ECHO_RAM_START, defs::MMUAddresses::ECHO_RAM_END)) {
                // Echo RAM
                return m_wram.Read(addr - (defs::MMUAddresses::ECHO_RAM_START - defs::MMUAddresses::WRAM_END));
            }

            else if (RANGE(addr, defs::MMUAddresses::OAM_START, defs::MMUAddresses::OAM_END)) {
                // Object attribute memory
                throw std::runtime_error("OAM not implemented");
            }

            else if (RANGE(addr, defs::MMUAddresses::UNUSABLE_START, defs::MMUAddresses::UNUSABLE_END)) {
                // Unusable memory
                throw std::runtime_error("Cannot read from unusable memory");
            }

            else if (RANGE(addr, defs::MMUAddresses::IO_REGISTER_START, defs::MMUAddresses::IO_REGISTER_END)) {
                // IO registers
                return m_io_controller.Read(addr);
            }

            else if (RANGE(addr, defs::MMUAddresses::HIGH_RAM_START, defs::MMUAddresses::HIGH_RAM_END)) {
                // High RAM
                throw std::runtime_error("High RAM not implemented");
            }

            else if (addr == defs::MMUAddresses::INTERRUPT_ENABLE) {
                // Interrupt enable register
                throw std::runtime_error("Interrupt enable register not implemented");
            }

            throw std::runtime_error("Attempted to read from unimplemented memory address: " + std::to_string(addr));
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
        case 0xA:
        case 0xB:
            m_cartridge.Write(addr, val);
            break;

        case 0x8:
        case 0x9:
            m_vram.Write(addr, val);
            break;

        case 0xC:
        case 0xD:
            m_wram.Write(addr, val);
            break;

        default:
            if (RANGE(addr, defs::MMUAddresses::ECHO_RAM_START, defs::MMUAddresses::ECHO_RAM_END)) {
                // Echo RAM
                m_wram.Write(addr - (defs::MMUAddresses::ECHO_RAM_START - defs::MMUAddresses::WRAM_END), val);
            }

            else if (RANGE(addr, defs::MMUAddresses::OAM_START, defs::MMUAddresses::OAM_END)) {
                // Object attribute memory
                throw std::runtime_error("OAM not implemented");
            }

            else if (RANGE(addr, defs::MMUAddresses::UNUSABLE_START, defs::MMUAddresses::UNUSABLE_END)) {
                // Unusable memory
                throw std::runtime_error("Cannot read from unusable memory");
            }

            else if (RANGE(addr, defs::MMUAddresses::IO_REGISTER_START, defs::MMUAddresses::IO_REGISTER_END)) {
                // IO registers
                m_io_controller.Write(addr, val);
            }

            else if (RANGE(addr, defs::MMUAddresses::HIGH_RAM_START, defs::MMUAddresses::HIGH_RAM_END)) {
                // High RAM
                throw std::runtime_error("High RAM not implemented");
            }

            else if (addr == defs::MMUAddresses::INTERRUPT_ENABLE) {
                // Interrupt enable register
                throw std::runtime_error("Interrupt enable register not implemented");
            }

            throw std::runtime_error("Attempted to read from unimplemented memory address: " + std::to_string(addr));
    }
}