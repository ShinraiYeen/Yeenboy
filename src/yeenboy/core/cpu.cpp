#include "yeenboy/core/cpu.hpp"

#include <stdio.h>

CPU::CPU(MemoryBus& mem) : m_mem(mem), m_af(m_a, m_f), m_bc(m_b, m_c), m_de(m_d, m_e), m_hl(m_h, m_l) {
    printf("CPU initialized\n");
}
