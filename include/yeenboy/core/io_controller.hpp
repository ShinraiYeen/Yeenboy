#pragma once

#include <cstddef>

#include "yeenboy/common/types.hpp"
#include "yeenboy/core/mmu_module.hpp"

class IOController : public MMUModule {
   public:
    IOController() = default;
    ~IOController() = default;

    u8 Read(size_t addr) const override;
    void Write(size_t addr, u8 val) override;

   private:
};