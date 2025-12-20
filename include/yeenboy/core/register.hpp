#pragma once

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
    explicit Register(T val) : m_val(val) {}
    ~Register() = default;

    T Value() const { return m_val; }
    void Set(T val) { m_val = val; }
    int BitWidth() const { return sizeof(T) * 8; }

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
    PairRegister(Register<u8>& high, Register<u8>& low);
    ~PairRegister() = default;

    u16 Value() const;
    void Set(u16 val);

   private:
    Register<u8>& m_high;
    Register<u8>& m_low;
};

/**
 * @brief Defines an 8-bit flag register.
 *
 * Defines the flag register for the Gameboy's CPU. This is an 8-bit register with its corresponding flags defined at
 * the highest 4 bits of the register's value.
 */
class FlagRegister : public Register<u8> {
   public:
    static constexpr int kZeroFlagBit = 7;
    static constexpr int kNegativeFlagBit = 6;
    static constexpr int kHalfCarryFlagBit = 5;
    static constexpr int kCarryFlagBit = 4;

    FlagRegister() = default;
    ~FlagRegister() = default;

    bool Zero() const { return util::CheckBit(m_val, kZeroFlagBit); };
    bool Negative() const { return util::CheckBit(m_val, kNegativeFlagBit); }
    bool HalfCarry() const { return util::CheckBit(m_val, kHalfCarryFlagBit); }
    bool Carry() const { return util::CheckBit(m_val, kCarryFlagBit); }

    void SetZero(bool set) { m_val = util::SetBitTo(m_val, kZeroFlagBit, set); }
    void SetNegative(bool set) { m_val = util::SetBitTo(m_val, kNegativeFlagBit, set); }
    void SetHalfCarry(bool set) { m_val = util::SetBitTo(m_val, kHalfCarryFlagBit, set); }
    void SetCarry(bool set) { m_val = util::SetBitTo(m_val, kCarryFlagBit, set); }
};