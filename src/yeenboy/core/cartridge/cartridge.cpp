#include "yeenboy/core/cartridge/cartridge.hpp"

#include <fstream>
#include <memory>
#include <stdexcept>
#include <unordered_map>

#include "yeenboy/common/logger.hpp"
#include "yeenboy/core/cartridge/mbc/mbc1.hpp"

const std::unordered_map<CartridgeType, std::string> kCartridgeTypeToString = {
    {CartridgeType::kRomOnly, "ROM Only"},
    {CartridgeType::kMBC1, "MBC1"},
    {CartridgeType::kMBC1Ram, "MBC1+RAM"},
    {CartridgeType::kMBC1RamBattery, "MBC1+RAM+BATTERY"},
    {CartridgeType::kMBC2, "MBC2"},
    {CartridgeType::kMBC2Battery, "MBC2+BATTERY"},
    {CartridgeType::kRomRam, "ROM+RAM"},
    {CartridgeType::kRomRamBattery, "ROM+RAM+BATTERY"},
    {CartridgeType::kMMM01, "MMM01"},
    {CartridgeType::kMMM01Ram, "MMM01+RAM"},
    {CartridgeType::kMMM01RamBattery, "MMM01+RAM+BATTERY"},
    {CartridgeType::kMBC3TimerBattery, "MBC3+TIMER+BATTERY"},
    {CartridgeType::kMBC3TimerRamBattery, "MBC3+TIMER+RAM+BATTERY"},
    {CartridgeType::kMBC3, "MBC3"},
    {CartridgeType::kMBC3Ram, "MBC3+RAM"},
    {CartridgeType::kMBC3RamBattery, "MBC3+RAM+BATTERY"},
    {CartridgeType::kMBC5, "MBC5"},
    {CartridgeType::kMBC5Ram, "MBC5+RAM"},
    {CartridgeType::kMBC5RamBattery, "MBC5+RAM+BATTERY"},
    {CartridgeType::kMBC5Rumble, "MBC5+RUMBLE"},
    {CartridgeType::kMBC5RumbleRam, "MBC5+RUMBLE+RAM"},
    {CartridgeType::kMBC7SensorRumbleRamBattery, "MBC5+RUMBLE+RAM+BATTERY"},
    {CartridgeType::kMBC6, "MBC6"},
    {CartridgeType::kMBC7SensorRumbleRamBattery, "MBC7+SENSOR+RUMBLE+RAM+BATTERY"},
    {CartridgeType::kPocketCamera, "POCKET CAMERA"},
    {CartridgeType::kBandaiTama5, "BANDAI TAMA5"},
    {CartridgeType::kHuC3, "HuC3"},
    {CartridgeType::kHuC1RamBattery, "HuC1+RAM+BATTERY"},
};

const std::unordered_map<RomSize, std::string> kRomSizeToString = {
    {RomSize::kKb32, "32Kb"},   {RomSize::kKb64, "64Kb"},  {RomSize::kKb128, "128Kb"}, {RomSize::kKb256, "256Kb"},
    {RomSize::kKb512, "512Kb"}, {RomSize::kMb1, "1Mb"},    {RomSize::kMb2, "2Mb"},     {RomSize::kMb4, "4Mb"},
    {RomSize::kMb8, "8Mb"},     {RomSize::kMb11, "1.1Mb"}, {RomSize::kMb12, "1.2Mb"},  {RomSize::kMb15, "1.5Mb"},
};

const std::unordered_map<RamSize, std::string> kRamSizeToString = {
    {RamSize::kNone, "None"}, {RamSize::kUnused, "Unused"}, {RamSize::kKb8, "8Kb"},
    {RamSize::kKb32, "32Kb"}, {RamSize::kKb128, "128Kb"},   {RamSize::kKb64, "64Kb"},
};

CartridgeHeader Cartridge::ReadCartridgeHeader() {
    CartridgeHeader header;

    header.cgb_flag = m_data.at(cartridge_header_addresses::kCgbFlag);
    header.sgb_flag = m_data.at(cartridge_header_addresses::kSgbFlag);
    header.destination_code = m_data.at(cartridge_header_addresses::kDestinationCode);
    header.rom_size = static_cast<RomSize>(m_data.at(cartridge_header_addresses::kRomSize));
    header.ram_size = static_cast<RamSize>(m_data.at(cartridge_header_addresses::kRamSize));
    header.title = std::string(reinterpret_cast<char*>(m_data.data() + cartridge_header_addresses::kTitleStart),
                               cartridge_header_addresses::kTitleEnd - cartridge_header_addresses::kTitleStart);
    header.cartridge_type = static_cast<CartridgeType>(m_data.at(cartridge_header_addresses::kCartridgeType));

    return header;
}

std::unique_ptr<MBC> Cartridge::GetMBC(CartridgeType type) {
    switch (type) {
        case CartridgeType::kMBC1:
        case CartridgeType::kMBC1Ram:
        case CartridgeType::kMBC1RamBattery:
            return std::make_unique<MBC1>(m_data, m_sram);
        default:
            throw std::runtime_error("Unsupported cartridge type");
    }
}

Cartridge::Cartridge(const std::filesystem::path& rom_path) {
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

void Cartridge::Write(size_t addr, u8 val) { m_mbc->Write(addr, val); }
u8 Cartridge::Read(size_t addr) const { return m_mbc->Read(addr); }
