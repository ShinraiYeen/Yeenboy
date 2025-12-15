#include "yeenboy/core/cartridge.hpp"

#include <cstdint>
#include <fstream>
#include <stdexcept>

CartridgeHeader Cartridge::ReadCartridgeHeader() {
    CartridgeHeader header;

    header.cgb_flag = m_data.at(CartridgeHeaderAddresses::CGB_FLAG);
    header.sgb_flag = m_data.at(CartridgeHeaderAddresses::SGB_FLAG);
    header.destination_code = m_data.at(CartridgeHeaderAddresses::DESTINATION_CODE);
    header.rom_size = static_cast<RomSize>(m_data.at(CartridgeHeaderAddresses::ROM_SIZE));
    header.ram_size = static_cast<RamSize>(m_data.at(CartridgeHeaderAddresses::RAM_SIZE));
    header.title = std::string(reinterpret_cast<char*>(m_data.data() + CartridgeHeaderAddresses::TITLE_START), 16);
    header.cartridge_type = static_cast<CartridgeType>(m_data.at(CartridgeHeaderAddresses::CARTRIDGE_TYPE));

    return header;
}

Cartridge::Cartridge(const std::filesystem::path rom_path) {
    std::ifstream file(rom_path);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open cartridge file: " + rom_path.string());
    }

    // Load all cartridge data into memory
    file.seekg(0, std::ios::end);
    size_t file_size = file.tellg();
    file.seekg(0, std::ios::beg);
    m_data.resize(file_size);
    file.read(reinterpret_cast<char*>(m_data.data()), file_size);
    printf("Loaded %lu bytes into cartridge memory\n", file_size);

    m_header = ReadCartridgeHeader();
    printf("Title: %s\n", m_header.title.c_str());
    printf("ROM Size: %02hhx\n", static_cast<uint8_t>(m_header.rom_size));
    printf("RAM Size: %02hhx\n", static_cast<uint8_t>(m_header.ram_size));
    printf("Cartridge Type: %s\n", kCartridgeTypeToString.at(m_header.cartridge_type).c_str());

    printf("Cartridge initialized\n");
}
