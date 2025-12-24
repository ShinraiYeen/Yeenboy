#include "yeenboy/common/logger.hpp"
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