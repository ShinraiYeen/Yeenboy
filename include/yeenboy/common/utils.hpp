#include <stdint.h>

namespace util {
inline uint8_t SetBit(uint8_t val, uint8_t bit) { return val | (1UL << bit); }
inline uint8_t ClearBit(uint8_t val, uint8_t bit) { return val & (~(1UL << bit)); }
inline uint8_t SetBitTo(uint8_t val, uint8_t bit, bool set) { return set ? SetBit(val, bit) : ClearBit(val, bit); }
inline bool CheckBit(uint8_t val, uint8_t bit) { return (val >> bit) & 1UL; }
}  // namespace util