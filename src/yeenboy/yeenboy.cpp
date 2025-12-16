#include "yeenboy/yeenboy.hpp"

Yeenboy::Yeenboy(const std::filesystem::path& path)
    : m_cartridge(path), m_mmu(m_wram, m_vram, m_cartridge, m_io_controller), m_cpu(m_mmu) {}
