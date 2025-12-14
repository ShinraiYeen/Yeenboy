#pragma once

#include "yeenboy/core/memory_bus.hpp"
#include "yeenboy/core/register.hpp"

/**
 * @brief Defines the Gameboy DMG's CPU.
 *
 */
class CPU {
   public:
    static constexpr unsigned int T_CLOCK_SPEED_HZ = 4194304;               // 4.194304 MHz
    static constexpr unsigned int M_CLOCK_SPEED_HZ = T_CLOCK_SPEED_HZ / 4;  // 1.048576 MHz

    CPU() = delete;
    CPU(MemoryBus& mem) : m_mem(mem), m_af(m_a, m_f), m_bc(m_b, m_c), m_de(m_d, m_e), m_hl(m_h, m_l) {}
    ~CPU() = default;

   private:
    MemoryBus& m_mem;  // Memory bus

    // CPU registers
    Register<uint8_t> m_a, m_b, m_c, m_d, m_e, m_h, m_l;  // Standard 8-bit registers
    Register<uint16_t> m_pc;                              // Program counter
    PairRegister m_af, m_bc, m_de, m_hl;                  // Pair registers
    Register<uint16_t> m_sp;                              // Stack pointer
    FlagRegister m_f;                                     // Flag register
};