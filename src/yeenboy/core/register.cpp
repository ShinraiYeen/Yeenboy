#include "yeenboy/core/register.hpp"

PairRegister::PairRegister(Register<uint8_t>& high, Register<uint8_t>& low) : m_high(high), m_low(low) {}

uint16_t PairRegister::Value() const { return util::CombineBytes(m_high.Value(), m_low.Value()); }

void PairRegister::Set(uint16_t val) {
    m_high.Set(util::ExtractHigh(val));
    m_low.Set(util::ExtractLow(val));
}
