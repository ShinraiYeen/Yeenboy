#include "yeenboy/core/register.hpp"

PairRegister::PairRegister(Register<uint8_t>& high, Register<uint8_t>& low) : m_high(high), m_low(low) {}

uint16_t PairRegister::Value() const {
    return (static_cast<uint16_t>(m_high.Value()) << 8) | static_cast<uint16_t>(m_low.Value());
}

void PairRegister::Set(uint16_t val) {
    m_high.Set(static_cast<uint8_t>(val >> 8));
    m_low.Set(static_cast<uint8_t>(val & 0xFF));
}
