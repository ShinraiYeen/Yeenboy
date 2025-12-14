#pragma once

#include <cstdint>
#include <type_traits>

#include "yeenboy/common/utils.hpp"

/**
 * @brief Defines a generic CPU register.
 *
 * @tparam T The underlying type of the register. Must be an unsigned integral type.
 */
template <typename T, typename = std::enable_if_t<std::is_integral_v<T> && std::is_unsigned_v<T>>>
class Register {
   public:
    Register() = default;
    Register(T val) : m_val(val) {}
    ~Register() = default;

    inline T Value() const { return m_val; }
    inline void Set(T val) { m_val = val; }
    inline int BitWidth() const { return sizeof(T) * 8; }

   protected:
    T m_val = 0;
};

/**
 * @brief Defines a paired register.
 *
 * Paired registers refer to two 8-bit registers to define their high and low values. Changes to this register will
 * directly result in changes to the referenced 8-bit registers. This is by design and made to emulate the Gameboy's
 * 16-bit arithmetic.
 *
 */
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

/**
 * @brief Defines an 8-bit flag register.
 *
 * Defines the flag register for the Gameboy's CPU. This is an 8-bit register with its corresponding flags defined at
 * the highest 4 bits of the register's value.
 */
class FlagRegister : public Register<uint8_t> {
   public:
    static constexpr int ZERO_FLAG_BIT = 7;
    static constexpr int SUBTRACT_FLAG_BIT = 6;
    static constexpr int HALF_CARRY_FLAG_BIT = 5;
    static constexpr int CARRY_FLAG_BIT = 4;

    FlagRegister() = default;
    ~FlagRegister() = default;

    inline bool Zero() const { return util::CheckBit(m_val, ZERO_FLAG_BIT); };
    inline bool Subtract() const { return util::CheckBit(m_val, SUBTRACT_FLAG_BIT); }
    inline bool HalfCarry() const { return util::CheckBit(m_val, HALF_CARRY_FLAG_BIT); }
    inline bool Carry() const { return util::CheckBit(m_val, CARRY_FLAG_BIT); }

    inline void SetZero(bool set) { m_val = util::SetBitTo(m_val, ZERO_FLAG_BIT, set); }
    inline void SetSubtract(bool set) { m_val = util::SetBitTo(m_val, SUBTRACT_FLAG_BIT, set); }
    inline void SetHalfCarry(bool set) { m_val = util::SetBitTo(m_val, HALF_CARRY_FLAG_BIT, set); }
    inline void SetCarry(bool set) { m_val = util::SetBitTo(m_val, CARRY_FLAG_BIT, set); }
};