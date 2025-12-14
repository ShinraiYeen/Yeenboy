#pragma once

#include "yeenboy/core/memory/memory.hpp"

static constexpr size_t VRAM_SIZE_BYTES = 8192;

class VRAM : public Memory<VRAM_SIZE_BYTES> {
   public:
    VRAM() = default;
    ~VRAM() = default;
};