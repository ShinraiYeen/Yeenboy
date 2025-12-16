#pragma once

#include <cstddef>
#include <cstdint>

#include "yeenboy/core/mmu_module.hpp"

class IOController : public MMUModule {
   public:
    IOController() = default;
    ~IOController() = default;

    uint8_t Read(size_t addr) const override;
    void Write(size_t addr, uint8_t val) override;

   private:
};