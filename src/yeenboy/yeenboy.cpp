#include "yeenboy/yeenboy.hpp"

Yeenboy::Yeenboy(const std::filesystem::path& path) : m_cartridge(path), m_mmu(m_wram, m_vram), m_cpu(m_mmu) {}
