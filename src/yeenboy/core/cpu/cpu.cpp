#include "yeenboy/core/cpu/cpu.hpp"

#include "yeenboy/common/logger.hpp"
#include "yeenboy/core/register.hpp"

CPU::CPU(MemoryBus& mem) : m_mem(mem), m_af(m_a, m_f), m_bc(m_b, m_c), m_de(m_d, m_e), m_hl(m_h, m_l) {
    Logger::Debug("CPU initialized");
}

void CPU::Tick() { (this->*kOpcodeMap.at(0x00))(); }

u8 CPU::GetPCByte() {
    const u8 val = m_mem.Read(m_pc.Value());
    m_pc.Set(m_pc.Value() + 1);
    return val;
}

u16 CPU::GetPCWord() {
    const u8 low = GetPCByte();
    const u8 high = GetPCByte();
    return util::CombineBytes(high, low);
}