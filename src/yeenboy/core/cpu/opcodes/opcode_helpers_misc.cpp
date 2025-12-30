#include <stdexcept>

#include "yeenboy/common/logger.hpp"
#include "yeenboy/common/utils.hpp"
#include "yeenboy/core/cpu/cpu.hpp"

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

int CPU::OpcodeILLEGAL() {
    throw std::runtime_error("Illegal opcode encountered");
    return 0;
}

u8 CPU::InternalSwap(u8 val) {
    const u8 high = util::ExtractHighNibble(val);
    const u8 low = util::ExtractLowNibble(val);
    const u8 result = util::CombineNibbles(high, low);

    m_f.SetZero(result == 0x00);
    m_f.SetNegative(false);
    m_f.SetHalfCarry(false);
    m_f.SetCarry(false);

    return result;
}

int CPU::OpcodeSWAP(Register<u8>& reg) {
    reg.Set(InternalSwap(reg.Value()));
    return 2;
}

int CPU::OpcodeSWAP(Register<u16>& addr) {
    const u8 val = m_mem.Read(addr.Value());
    const u8 result = InternalSwap(val);
    m_mem.Write(addr.Value(), result);
    return 4;
}