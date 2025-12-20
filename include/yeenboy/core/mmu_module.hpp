#pragma once

#include <cstddef>

#include "yeenboy/common/types.hpp"

/**
 * @brief Generic interface for memory.
 */
class MMUModule {
   public:
    virtual ~MMUModule() = default;

    virtual u8 Read(size_t addr) const = 0;
    virtual void Write(size_t addr, u8 val) = 0;

   protected:
    MMUModule() = default;
};