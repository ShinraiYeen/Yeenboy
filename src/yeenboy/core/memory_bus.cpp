#include "yeenboy/core/memory_bus.hpp"

#include <stdio.h>

MemoryBus::MemoryBus(WRAM& wram, VRAM& vram) : m_wram(wram), m_vram(vram) { printf("Memory bus initialized\n"); }
