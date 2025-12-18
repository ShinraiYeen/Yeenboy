#pragma once

#include <cstddef>
namespace defs {
static constexpr std::size_t kBankSize = 0x4000;  // 16Kb

namespace mmu_addresses {
static constexpr size_t kRomBank00Start = 0x0000;
static constexpr size_t kRomBank00End = 0x3FFF;
static constexpr size_t kRomBankNnStart = 0x4000;
static constexpr size_t kRomBankNnEnd = 0x7FFF;
static constexpr size_t kVramStart = 0x8000;
static constexpr size_t kVramEnd = 0x9FFF;
static constexpr size_t kExternalRamStart = 0xA000;
static constexpr size_t kExternalRamEnd = 0xBFFF;
static constexpr size_t kWramStart = 0xC000;
static constexpr size_t kWramEnd = 0xDFFF;
static constexpr size_t kEchoRamStart = 0xE000;
static constexpr size_t kEchoRamEnd = 0xFDFF;
static constexpr size_t kOamStart = 0xFE00;
static constexpr size_t kOamEnd = 0xFE9F;
static constexpr size_t kUnusableStart = 0xFEA0;
static constexpr size_t kUnusableEnd = 0xFEFF;
static constexpr size_t kIORegisterStart = 0xFF00;
static constexpr size_t kIORegisterEnd = 0xFF7F;
static constexpr size_t kHighRamStart = 0xFF80;
static constexpr size_t kHighRamEnd = 0xFFFE;
static constexpr size_t kInterruptEnable = 0xFFFF;
}  // namespace mmu_addresses
}  // namespace defs
