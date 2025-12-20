#include "yeenboy/core/register.hpp"

PairRegister::PairRegister(Register<u8>& high, Register<u8>& low) : m_high(high), m_low(low) {}

u16 PairRegister::Value() const { return util::CombineBytes(m_high.Value(), m_low.Value()); }

void PairRegister::Set(u16 val) {
    m_high.Set(util::ExtractHigh(val));
    m_low.Set(util::ExtractLow(val));
}
