#pragma once

#include "yeenboy/common/types.hpp"

namespace util {
inline u8 SetBit(u8 val, u8 bit) { return val | (1UL << bit); }
inline u8 ClearBit(u8 val, u8 bit) { return val & (~(1UL << bit)); }
inline u8 SetBitTo(u8 val, u8 bit, bool set) { return set ? SetBit(val, bit) : ClearBit(val, bit); }
inline bool CheckBit(u8 val, u8 bit) { return ((val >> bit) & 1UL) != 0U; }

inline u16 CombineBytes(u8 high, u8 low) { return static_cast<u16>(high << 8) | static_cast<u16>(low); }
inline u8 CombineNibbles(u8 high, u8 low) { return static_cast<u8>((high << 4) | (low & 0xF)); }
inline u8 ExtractLow(u16 val) { return static_cast<u8>(val & 0xFF); }
inline u8 ExtractHigh(u16 val) { return static_cast<u8>((val >> 8) & 0xFF); }

inline u8 ExtractHighNibble(u8 val) { return static_cast<u8>((val >> 4) & 0xF); }
inline u8 ExtractLowNibble(u8 val) { return static_cast<u8>(val & 0xF); }

template <typename T>
inline bool InRange(T val, T start, T end) {
    return ((val) >= (start)) && ((val) <= (end));
}
}  // namespace util