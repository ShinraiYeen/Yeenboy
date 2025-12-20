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

u8 MemoryBus::Read(size_t addr) {
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
            if (RANGE(addr, defs::mmu_addresses::kEchoRamStart, defs::mmu_addresses::kEchoRamEnd)) {
                // Echo RAM
                return m_wram.Read(addr - (defs::mmu_addresses::kEchoRamStart - defs::mmu_addresses::kWramEnd));
            }

            else if (RANGE(addr, defs::mmu_addresses::kOamStart, defs::mmu_addresses::kOamEnd)) {
                // Object attribute memory
                throw std::runtime_error("OAM not implemented");
            }

            else if (RANGE(addr, defs::mmu_addresses::kUnusableStart, defs::mmu_addresses::kUnusableEnd)) {
                // Unusable memory
                throw std::runtime_error("Cannot read from unusable memory");
            }

            else if (RANGE(addr, defs::mmu_addresses::kIORegisterStart, defs::mmu_addresses::kIORegisterEnd)) {
                // IO registers
                return m_io_controller.Read(addr);
            }

            else if (RANGE(addr, defs::mmu_addresses::kHighRamStart, defs::mmu_addresses::kHighRamEnd)) {
                // High RAM
                throw std::runtime_error("High RAM not implemented");
            }

            else if (addr == defs::mmu_addresses::kInterruptEnable) {
                // Interrupt enable register
                throw std::runtime_error("Interrupt enable register not implemented");
            }

            throw std::runtime_error("Attempted to read from unimplemented memory address: " + std::to_string(addr));
    }
}

void MemoryBus::Write(size_t addr, u8 val) {
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
            if (RANGE(addr, defs::mmu_addresses::kEchoRamStart, defs::mmu_addresses::kEchoRamEnd)) {
                // Echo RAM
                m_wram.Write(addr - (defs::mmu_addresses::kEchoRamStart - defs::mmu_addresses::kWramEnd), val);
            }

            else if (RANGE(addr, defs::mmu_addresses::kOamStart, defs::mmu_addresses::kOamEnd)) {
                // Object attribute memory
                throw std::runtime_error("OAM not implemented");
            }

            else if (RANGE(addr, defs::mmu_addresses::kUnusableStart, defs::mmu_addresses::kUnusableEnd)) {
                // Unusable memory
                throw std::runtime_error("Cannot read from unusable memory");
            }

            else if (RANGE(addr, defs::mmu_addresses::kIORegisterStart, defs::mmu_addresses::kIORegisterEnd)) {
                // IO registers
                m_io_controller.Write(addr, val);
            }

            else if (RANGE(addr, defs::mmu_addresses::kHighRamStart, defs::mmu_addresses::kHighRamEnd)) {
                // High RAM
                throw std::runtime_error("High RAM not implemented");
            }

            else if (addr == defs::mmu_addresses::kInterruptEnable) {
                // Interrupt enable register
                throw std::runtime_error("Interrupt enable register not implemented");
            }

            throw std::runtime_error("Attempted to read from unimplemented memory address: " + std::to_string(addr));
    }
}