#include "yeenboy/core/cpu/cpu.hpp"
#include "yeenboy/core/register.hpp"

u8 CPU::InternalBitSet(u8 value, u8 bit, bool set) { return util::SetBitTo(value, bit, set); }

int CPU::OpcodeSetBitTo(Register<u8>& reg, u8 bit, bool set) {
    reg.Set(InternalBitSet(reg.Value(), bit, set));
    return 2;
}

int CPU::OpcodeSetBitTo(Register<u16>& addr, u8 bit, bool set) {
    const u8 in_val = m_mem.Read(addr.Value());
    m_mem.Write(addr.Value(), InternalBitSet(in_val, bit, set));
    return 4;
}

void CPU::InternalBitCheck(u8 value, u8 bit) {
    m_f.SetZero(!util::CheckBit(value, bit));
    m_f.SetNegative(false);
    m_f.SetHalfCarry(true);
}

int CPU::OpcodeBIT(Register<u8>& reg, u8 bit) {
    InternalBitCheck(reg.Value(), bit);
    return 2;
}

int CPU::OpcodeBIT(Register<u16>& reg, u8 bit) {
    InternalBitCheck(m_mem.Read(reg.Value()), bit);
    return 3;
}
