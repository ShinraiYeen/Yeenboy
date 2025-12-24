#include "yeenboy/core/cpu/cpu.hpp"
#include "yeenboy/core/register.hpp"

int CPU::OpcodeLD(Register<u16>& store_addr, Register<u8>& load_reg) {
    m_mem.Write(store_addr.Value(), load_reg.Value());
    return 2;
}

int CPU::OpcodeLD(Register<u8>& store_reg, Register<u16>& load_addr) {
    store_reg.Set(m_mem.Read(load_addr.Value()));
    return 2;
}

int CPU::OpcodeLD(Register<u8>& store_reg, Register<u8>& load_reg) {
    (void)m_a;
    store_reg.Set(load_reg.Value());
    return 1;
}

int CPU::OpcodeLD(Register<u16>& store_reg) {
    u8 low = GetPCByte();
    u8 high = GetPCByte();
    u16 val = util::CombineBytes(high, low);
    store_reg.Set(val);
    return 3;
}

int CPU::OpcodeLD(Register<u8>& store_reg) {
    store_reg.Set(GetPCByte());
    return 2;
}