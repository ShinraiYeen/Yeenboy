#include "yeenboy/core/memory/vram.hpp"

#include "yeenboy/common/defs.hpp"
#include "yeenboy/common/logger.hpp"

VRAM::VRAM() { Logger::Debug("VRAM initialized"); }

u8 VRAM::Read(size_t addr) const { return m_data.at(addr - defs::mmu_addresses::kVramStart); }

void VRAM::Write(size_t addr, u8 val) { m_data.at(addr - defs::mmu_addresses::kVramStart) = val; }
