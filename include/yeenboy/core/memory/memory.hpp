#pragma once

#include <stdint.h>

#include <cstddef>

/**
 * @brief Generic interface for memory.
 */
class Memory {
   public:
    virtual ~Memory() = default;

    virtual uint8_t Read(size_t addr) const = 0;
    virtual void Write(size_t addr, uint8_t val) = 0;

   protected:
    Memory() = default;
};