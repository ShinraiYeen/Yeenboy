#pragma once

#include <stdint.h>

#include <array>
#include <cstddef>

/**
 * @brief Generic interface for fixed sized memory.
 *
 * @tparam S The number of bytes to be used for this fixed sized memory.
 */
template <size_t S>
class Memory {
   public:
    Memory() = default;
    ~Memory() = default;

    inline uint8_t& at(size_t index) { return m_data.at(index); }
    inline uint8_t& operator[](size_t index) { return m_data.at(index); }
    inline constexpr size_t Size() { return S; }

   protected:
    std::array<uint8_t, S> m_data;
};