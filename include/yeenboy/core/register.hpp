#pragma once

#include <cstdint>

template <typename T>
class Register {
   public:
    Register() = default;
    ~Register() = default;

    inline T Value() const { return m_val; }
    inline void Set(T val) { m_val = val; }

   protected:
    T m_val;
};

class PairRegister {
   public:
    PairRegister(Register<uint8_t>& high, Register<uint8_t>& low);
    ~PairRegister() = default;

    uint16_t Value() const;
    void Set(uint16_t val);

   private:
    Register<uint8_t>& m_high;
    Register<uint8_t>& m_low;
};

class FlagRegister : public Register<uint8_t> {};