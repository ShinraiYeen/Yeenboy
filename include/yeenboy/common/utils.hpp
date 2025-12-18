#include <cstdint>

namespace util {
inline uint8_t SetBit(uint8_t val, uint8_t bit) { return val | (1UL << bit); }
inline uint8_t ClearBit(uint8_t val, uint8_t bit) { return val & (~(1UL << bit)); }
inline uint8_t SetBitTo(uint8_t val, uint8_t bit, bool set) { return set ? SetBit(val, bit) : ClearBit(val, bit); }
inline bool CheckBit(uint8_t val, uint8_t bit) { return ((val >> bit) & 1UL) != 0U; }

inline uint16_t CombineBytes(uint8_t high, uint8_t low) {
    return static_cast<uint16_t>(high << 8) | static_cast<uint16_t>(low);
}
inline uint8_t ExtractLow(uint16_t val) { return static_cast<uint8_t>(val & 0xFF); }

inline uint8_t ExtractHigh(uint16_t val) { return static_cast<uint8_t>((val >> 8) & 0xFF); }

#define RANGE(var, start, end) (((var) >= (start)) && ((var) <= (end)))
}  // namespace util