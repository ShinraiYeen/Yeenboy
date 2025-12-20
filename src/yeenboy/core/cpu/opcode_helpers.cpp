#include "yeenboy/common/logger.hpp"
#include "yeenboy/core/cpu/cpu.hpp"
#include "yeenboy/core/register.hpp"

int CPU::OpcodeNOP() {
    (void)m_a;  // Stupid fix for clang-tidy bullshit
    Logger::Debug("Calling NOP");
    return 1;
}

int CPU::OpcodeSTOP() {
    m_halt_cpu = true;
    return 1;
}

int CPU::OpcodeHALT() {
    // TODO(shinraiyeen): This is a different type of halt which will wait for an interrupt before resuming CPU
    // operations
    m_halt_cpu = true;
    return 1;
}

int CPU::OpcodeLD(PairRegister& store_addr, Register<u8>& load_reg) {
    m_mem.Write(store_addr.Value(), load_reg.Value());
    return 2;
}

int CPU::OpcodeLD(Register<u8>& store_reg, PairRegister& load_addr) {
    store_reg.Set(m_mem.Read(load_addr.Value()));
    return 2;
}

int CPU::OpcodeLD(Register<u8>& store_reg, Register<u8>& load_reg) {
    (void)m_a;
    store_reg.Set(load_reg.Value());
    return 1;
}

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