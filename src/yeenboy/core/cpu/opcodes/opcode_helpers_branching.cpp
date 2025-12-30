#include "yeenboy/common/types.hpp"
#include "yeenboy/common/utils.hpp"
#include "yeenboy/core/cpu/cpu.hpp"

void CPU::InternalJump(u16 addr) { m_pc.Set(addr); }

int CPU::OpcodeJP() {
    InternalJump(GetPCWord());
    return 4;
}

int CPU::OpcodeJP(bool condition_result) {
    if (condition_result) {
        return OpcodeJP();
    }

    GetPCWord();  // Consume unused word
    return 3;
}

int CPU::OpcodeJP(Register<u16>& reg) {
    InternalJump(reg.Value());
    return 1;
}

void CPU::InternalJumpRelative(i8 val) { m_pc.Set(m_pc.Value() + val); }

int CPU::OpcodeJR() {
    const i8 offset = static_cast<i8>(GetPCByte());
    InternalJumpRelative(offset);
    return 3;
}

int CPU::OpcodeJR(bool condition_result) {
    if (condition_result) {
        return OpcodeJR();
    }

    GetPCByte();  // Consume unused byte
    return 2;
}

u16 CPU::InternalPop() {
    const u8 low = m_mem.Read(m_sp.Value());
    const u8 high = m_mem.Read(m_sp.Value() + 1);
    m_sp.Increment(2);
    return util::CombineBytes(high, low);
}

void CPU::InternalPush(u16 val) {
    const u8 low = util::ExtractLow(val);
    const u8 high = util::ExtractHigh(val);
    m_mem.Write(m_sp.Value() - 1, high);
    m_mem.Write(m_sp.Value() - 2, low);
    m_sp.Decrement(2);
}

int CPU::OpcodePOP(Register<u16>& reg) {
    reg.Set(InternalPop());
    return 3;
}

int CPU::OpcodePUSH(Register<u16>& reg) {
    InternalPush(reg.Value());
    return 4;
}

void CPU::InternalCall(u16 val) { InternalPush(val); }

int CPU::OpcodeCALL() {
    const u16 val = GetPCWord();
    InternalCall(val);
    return 6;
}

int CPU::OpcodeCALL(bool condition_result) {
    const u16 val = GetPCWord();
    if (condition_result) {
        InternalCall(val);
        return 6;
    }

    return 3;
}

void CPU::InternalReturn() { m_pc.Set(InternalPop()); }

int CPU::OpcodeRET() {
    InternalReturn();
    return 4;
}

int CPU::OpcodeRET(bool condition_result) {
    if (condition_result) {
        InternalReturn();
        return 5;
    }

    return 2;
}

int CPU::OpcodeRETI() {
    InternalReturn();
    m_interupt_master_enable = true;
    return 4;
}