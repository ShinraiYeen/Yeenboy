#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

class MBC {
   public:
    virtual ~MBC() = 0;

    virtual uint8_t ReadRom(size_t addr) const = 0;
    virtual uint8_t ReadRam(size_t addr) const = 0;

    virtual void WriteRom(size_t addr, uint8_t val) = 0;
    virtual void WriteRam(size_t addr, uint8_t val) = 0;

   private:
   protected:
    MBC(std::vector<uint8_t>& rom, std::vector<uint8_t>& ram) : m_rom(rom), m_ram(ram) {}
    std::vector<uint8_t>& m_rom;
    std::vector<uint8_t>& m_ram;
};