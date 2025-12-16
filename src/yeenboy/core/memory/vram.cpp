#include "yeenboy/core/memory/vram.hpp"

#include <stdexcept>

#include "yeenboy/common/logger.hpp"

VRAM::VRAM() : Memory() { Logger::Debug("VRAM initialized"); }

uint8_t VRAM::Read(size_t addr) const {
    if (addr >= VRAM_SIZE) throw std::runtime_error("Out of bounds read in VRAM");
    return m_data.at(addr);
}

void VRAM::Write(size_t addr, uint8_t val) {
    if (addr >= VRAM_SIZE) throw std::runtime_error("Out of bounds write in VRAM");
    m_data.at(addr) = val;
}
