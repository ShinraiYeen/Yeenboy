#pragma once

#include "yeenboy/core/memory/memory.hpp"

static constexpr size_t WRAM_SIZE_BYTES = 8192;

class WRAM : public Memory<WRAM_SIZE_BYTES> {
   public:
    WRAM();
    ~WRAM() = default;
};