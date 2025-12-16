#include "yeenboy/core/memory/wram.hpp"

#include "yeenboy/common/logger.hpp"

WRAM::WRAM() : Memory() { Logger::Debug("WRAM initialized"); }

uint8_t WRAM::Read(size_t addr) const {
    if (addr >= WRAM_SIZE) throw std::runtime_error("Out of bounds read in VRAM");
    return m_data.at(addr);
}

void WRAM::Write(size_t addr, uint8_t val) {
    if (addr >= WRAM_SIZE) throw std::runtime_error("Out of bounds write in VRAM");
    m_data.at(addr) = val;
}