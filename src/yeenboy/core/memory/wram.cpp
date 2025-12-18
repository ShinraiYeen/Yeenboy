#include "yeenboy/core/memory/wram.hpp"

#include "yeenboy/common/defs.hpp"
#include "yeenboy/common/logger.hpp"

WRAM::WRAM() { Logger::Debug("WRAM initialized"); }

uint8_t WRAM::Read(size_t addr) const { return m_data.at(addr - defs::mmu_addresses::kWramStart); }

void WRAM::Write(size_t addr, uint8_t val) { m_data.at(addr - defs::mmu_addresses::kWramStart) = val; }