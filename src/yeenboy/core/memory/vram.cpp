#include "yeenboy/core/memory/vram.hpp"

#include "yeenboy/common/defs.hpp"
#include "yeenboy/common/logger.hpp"

VRAM::VRAM() : MMUModule() { Logger::Debug("VRAM initialized"); }

uint8_t VRAM::Read(size_t addr) const { return m_data.at(addr - defs::mmu_addresses::VRAM_START); }

void VRAM::Write(size_t addr, uint8_t val) { m_data.at(addr - defs::mmu_addresses::VRAM_START) = val; }
