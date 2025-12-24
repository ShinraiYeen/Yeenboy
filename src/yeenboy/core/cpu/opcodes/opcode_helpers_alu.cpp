#include "yeenboy/core/cpu/cpu.hpp"

int CPU::OpcodeINC(Register<u8>& reg) {
    const u8 original_val = reg.Value();
    const u8 result = original_val + 1;

    m_f.SetZero(result == 0x00);
    m_f.SetNegative(false);
    m_f.SetHalfCarry(((original_val & 0x0F) == 0xF));

    reg.Set(result);

    return 1;
}

int CPU::OpcodeDEC(Register<u8>& reg) {
    const u8 original_val = reg.Value();
    const u8 result = original_val - 1;

    m_f.SetZero(result == 0x00);
    m_f.SetNegative(true);
    m_f.SetHalfCarry(((original_val & 0x0F) == 0x00));

    reg.Set(result);

    return 1;
}

u8 CPU::InternalAdd(u8 val, u8 carry) {
    const u8 original_val = m_a.Value();
    const int full_result = original_val + val + carry;
    const u8 result = static_cast<u8>(full_result);

    m_f.SetZero(result == 0);
    m_f.SetNegative(false);
    m_f.SetCarry(full_result > 0xFF);
    m_f.SetHalfCarry((((original_val & 0xF) + (val & 0xF) + carry) > 0xF));

    return result;
}

u8 CPU::InternalAnd(u8 val) {
    const u8 result = m_a.Value() & val;

    m_f.SetZero(result == 0);
    m_f.SetNegative(false);
    m_f.SetHalfCarry(true);
    m_f.SetCarry(false);

    return result;
}

u8 CPU::InternalXor(u8 val) {
    const u8 result = m_a.Value() ^ val;

    m_f.SetZero(result == 0);
    m_f.SetNegative(false);
    m_f.SetHalfCarry(false);
    m_f.SetCarry(false);

    return result;
}

u8 CPU::InternalOr(u8 val) {
    const u8 result = m_a.Value() | val;

    m_f.SetZero(result == 0);
    m_f.SetNegative(false);
    m_f.SetHalfCarry(false);
    m_f.SetCarry(false);

    return result;
}

u8 CPU::InternalSub(u8 val, u8 carry) {
    const u8 original_val = m_a.Value();
    const int full_result = original_val - val - carry;
    const u8 result = static_cast<u8>(full_result);

    m_f.SetZero(result == 0);
    m_f.SetNegative(true);
    m_f.SetCarry(full_result < 0);
    m_f.SetHalfCarry(((original_val & 0xF) - (val & 0xF) - carry) < 0);

    return result;
}

int CPU::OpcodeADD(Register<u8>& reg) {
    m_a.Set(InternalAdd(reg.Value(), 0));
    return 1;
}

int CPU::OpcodeADD(Register<u16>& addr) {
    m_a.Set(InternalAdd(m_mem.Read(addr.Value()), 0));
    return 2;
}

int CPU::OpcodeADD() {
    m_a.Set(InternalAdd(GetPCByte(), 0));
    return 2;
}

int CPU::OpcodeADC(Register<u8>& reg) {
    u8 carry = m_f.Carry() ? 1 : 0;
    m_a.Set(InternalAdd(reg.Value(), carry));
    return 1;
}

int CPU::OpcodeADC(Register<u16>& addr) {
    u8 carry = m_f.Carry() ? 1 : 0;
    m_a.Set(InternalAdd(m_mem.Read(addr.Value()), carry));
    return 2;
}

int CPU::OpcodeADC() {
    u8 carry = m_f.Carry() ? 1 : 0;
    m_a.Set(InternalAdd(GetPCByte(), carry));
    return 2;
}

int CPU::OpcodeSUB(Register<u8>& reg) {
    m_a.Set(InternalSub(reg.Value(), 0));
    return 1;
}

int CPU::OpcodeSUB(Register<u16>& addr) {
    m_a.Set(InternalSub(m_mem.Read(addr.Value()), 0));
    return 2;
}

int CPU::OpcodeSUB() {
    m_a.Set(InternalSub(GetPCByte(), 0));
    return 2;
}

int CPU::OpcodeSBC(Register<u8>& reg) {
    u8 carry = m_f.Carry() ? 1 : 0;
    m_a.Set(InternalSub(reg.Value(), carry));
    return 1;
}

int CPU::OpcodeSBC(Register<u16>& addr) {
    u8 carry = m_f.Carry() ? 1 : 0;
    m_a.Set(InternalSub(m_mem.Read(addr.Value()), carry));
    return 2;
}

int CPU::OpcodeSBC() {
    u8 carry = m_f.Carry() ? 1 : 0;
    m_a.Set(InternalSub(GetPCByte(), carry));
    return 2;
}

int CPU::OpcodeAND(Register<u8>& reg) {
    m_a.Set(InternalAnd(reg.Value()));
    return 1;
}

int CPU::OpcodeAND(Register<u16>& addr) {
    m_a.Set(InternalAnd(m_mem.Read(addr.Value())));
    return 2;
}

int CPU::OpcodeAND() {
    m_a.Set(InternalAnd(GetPCByte()));
    return 2;
}

int CPU::OpcodeXOR(Register<u8>& reg) {
    m_a.Set(InternalXor(reg.Value()));
    return 1;
}

int CPU::OpcodeXOR(Register<u16>& addr) {
    m_a.Set(InternalXor(m_mem.Read(addr.Value())));
    return 2;
}

int CPU::OpcodeXOR() {
    m_a.Set(InternalXor(GetPCByte()));
    return 2;
}

int CPU::OpcodeOR(Register<u8>& reg) {
    m_a.Set(InternalOr(reg.Value()));
    return 1;
}

int CPU::OpcodeOR(Register<u16>& addr) {
    m_a.Set(InternalOr(m_mem.Read(addr.Value())));
    return 2;
}

int CPU::OpcodeOR() {
    m_a.Set(InternalOr(GetPCByte()));
    return 2;
}

int CPU::OpcodeCP(Register<u8>& reg) {
    InternalSub(reg.Value(), 0);
    return 1;
}

int CPU::OpcodeCP(Register<u16>& addr) {
    InternalSub(m_mem.Read(addr.Value()), 0);
    return 2;
}

int CPU::OpcodeCP() {
    InternalSub(GetPCByte(), 0);
    return 2;
}