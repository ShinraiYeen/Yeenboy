#include "yeenboy/core/cartridge/cartridge.hpp"

#include <fstream>
#include <memory>
#include <stdexcept>
#include <unordered_map>

#include "yeenboy/common/logger.hpp"
#include "yeenboy/core/cartridge/mbc/mbc1.hpp"

const std::unordered_map<CartridgeType, std::string> kCartridgeTypeToString = {
    {CartridgeType::ROM_ONLY, "ROM Only"},
    {CartridgeType::MBC1, "MBC1"},
    {CartridgeType::MBC1_RAM, "MBC1+RAM"},
    {CartridgeType::MBC1_RAM_BATTERY, "MBC1+RAM+BATTERY"},
    {CartridgeType::MBC2, "MBC2"},
    {CartridgeType::MBC2_BATTERY, "MBC2+BATTERY"},
    {CartridgeType::ROM_RAM, "ROM+RAM"},
    {CartridgeType::ROM_RAM_BATTERY, "ROM+RAM+BATTERY"},
    {CartridgeType::MMM01, "MMM01"},
    {CartridgeType::MMM01_RAM, "MMM01+RAM"},
    {CartridgeType::MMM01_RAM_BATTERY, "MMM01+RAM+BATTERY"},
    {CartridgeType::MBC3_TIMER_BATTERY, "MBC3+TIMER+BATTERY"},
    {CartridgeType::MBC3_TIMER_RAM_BATTERY, "MBC3+TIMER+RAM+BATTERY"},
    {CartridgeType::MBC3, "MBC3"},
    {CartridgeType::MBC3_RAM, "MBC3+RAM"},
    {CartridgeType::MBC3_RAM_BATTERY, "MBC3+RAM+BATTERY"},
    {CartridgeType::MBC5, "MBC5"},
    {CartridgeType::MBC5_RAM, "MBC5+RAM"},
    {CartridgeType::MBC5_RAM_BATTERY, "MBC5+RAM+BATTERY"},
    {CartridgeType::MBC5_RUMBLE, "MBC5+RUMBLE"},
    {CartridgeType::MBC5_RUMBLE_RAM, "MBC5+RUMBLE+RAM"},
    {CartridgeType::MBC5_RUMBLE_RAM_BATTERY, "MBC5+RUMBLE+RAM+BATTERY"},
    {CartridgeType::MBC6, "MBC6"},
    {CartridgeType::MBC7_SENSOR_RUMBLE_RAM_BATTERY, "MBC7+SENSOR+RUMBLE+RAM+BATTERY"},
    {CartridgeType::POCKET_CAMERA, "POCKET CAMERA"},
    {CartridgeType::BANDAI_TAMA5, "BANDAI TAMA5"},
    {CartridgeType::HuC3, "HuC3"},
    {CartridgeType::HuC1_RAM_BATTERY, "HuC1+RAM+BATTERY"},
};

const std::unordered_map<RomSize, std::string> kRomSizeToString = {
    {RomSize::KB_32, "32Kb"},   {RomSize::KB_64, "64Kb"},   {RomSize::KB_128, "128Kb"}, {RomSize::KB_256, "256Kb"},
    {RomSize::KB_512, "512Kb"}, {RomSize::MB_1, "1Mb"},     {RomSize::MB_2, "2Mb"},     {RomSize::MB_4, "4Mb"},
    {RomSize::MB_8, "8Mb"},     {RomSize::MB_1_1, "1.1Mb"}, {RomSize::MB_1_2, "1.2Mb"}, {RomSize::MB_1_5, "1.5Mb"},
};

const std::unordered_map<RamSize, std::string> kRamSizeToString = {
    {RamSize::NONE, "None"},  {RamSize::UNUSED, "Unused"}, {RamSize::KB_8, "8Kb"},
    {RamSize::KB_32, "32Kb"}, {RamSize::KB_128, "128Kb"},  {RamSize::KB_64, "64Kb"},
};

CartridgeHeader Cartridge::ReadCartridgeHeader() {
    CartridgeHeader header;

    header.cgb_flag = m_data.at(CartridgeHeaderAddresses::CGB_FLAG);
    header.sgb_flag = m_data.at(CartridgeHeaderAddresses::SGB_FLAG);
    header.destination_code = m_data.at(CartridgeHeaderAddresses::DESTINATION_CODE);
    header.rom_size = static_cast<RomSize>(m_data.at(CartridgeHeaderAddresses::ROM_SIZE));
    header.ram_size = static_cast<RamSize>(m_data.at(CartridgeHeaderAddresses::RAM_SIZE));
    header.title = std::string(reinterpret_cast<char*>(m_data.data() + CartridgeHeaderAddresses::TITLE_START),
                               CartridgeHeaderAddresses::TITLE_END - CartridgeHeaderAddresses::TITLE_START);
    header.cartridge_type = static_cast<CartridgeType>(m_data.at(CartridgeHeaderAddresses::CARTRIDGE_TYPE));

    return header;
}

std::unique_ptr<MBC> Cartridge::GetMBC(CartridgeType type) {
    switch (type) {
        case CartridgeType::MBC1:
        case CartridgeType::MBC1_RAM:
        case CartridgeType::MBC1_RAM_BATTERY:
            return std::make_unique<MBC1>(m_data, m_sram);
        default:
            throw std::runtime_error("Unsupported cartridge type");
    }
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
    Logger::Debug("Loaded {} bytes into cartridge memory", file_size);

    m_header = ReadCartridgeHeader();
    m_mbc = GetMBC(m_header.cartridge_type);

    Logger::Debug("Title: {}", m_header.title);
    Logger::Debug("MBC: {}", kCartridgeTypeToString.at(m_header.cartridge_type));
    Logger::Debug("ROM: {}", kRomSizeToString.at(m_header.rom_size));
    Logger::Debug("RAM: {}", kRamSizeToString.at(m_header.ram_size));

    Logger::Debug("Cartridge initialized");
}

void Cartridge::Write(size_t addr, uint8_t val) { m_mbc->Write(addr, val); }
uint8_t Cartridge::Read(size_t addr) const { return m_mbc->Read(addr); }
