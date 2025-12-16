#include "yeenboy/core/cartridge/mbc/mbc1.hpp"

#include "yeenboy/common/logger.hpp"

MBC1::MBC1(std::vector<uint8_t>& rom, std::vector<uint8_t>& ram) : MBC(rom, ram) { Logger::Debug("Initialized MBC1"); }

uint8_t MBC1::ReadRom(size_t addr) const {}
uint8_t MBC1::ReadRam(size_t addr) const {}

void MBC1::WriteRom(size_t addr, uint8_t val) {}
void MBC1::WriteRam(size_t addr, uint8_t val) {}