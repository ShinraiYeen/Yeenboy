#include "yeenboy/common/types.hpp"
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