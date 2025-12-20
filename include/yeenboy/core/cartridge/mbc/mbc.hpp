#pragma once

#include <cstddef>
#include <vector>

#include "yeenboy/common/types.hpp"

class MBC {
   public:
    virtual ~MBC() = default;

    virtual u8 Read(size_t addr) const = 0;
    virtual void Write(size_t addr, u8 val) = 0;

   private:
   protected:
    MBC(std::vector<u8>& rom, std::vector<u8>& ram) : m_rom(rom), m_ram(ram) {}
    std::vector<u8>& m_rom;
    std::vector<u8>& m_ram;
};