#pragma once

#include <filesystem>
#include <memory>
#include <unordered_map>
#include <vector>

#include "yeenboy/core/cartridge/mbc/mbc.hpp"
#include "yeenboy/core/mmu_module.hpp"

/**
 * @brief Defines addresses for cartridge header information.
 *
 */
namespace cartridge_header_addresses {
static constexpr size_t kTitleStart = 0x134;
static constexpr size_t kTitleEnd = 0x143;
static constexpr size_t kManufacturerCode = 0x13F;
static constexpr size_t kCgbFlag = 0x143;
static constexpr size_t kSgbFlag = 0x146;
static constexpr size_t kCartridgeType = 0x147;
static constexpr size_t kRomSize = 0x148;
static constexpr size_t kRamSize = 0x149;
static constexpr size_t kDestinationCode = 0x14A;
static constexpr size_t kOldLicenseeCode = 0x14B;
static constexpr size_t kMaskRomVersionNumber = 0x14C;
static constexpr size_t kHeaderChecksum = 0x14D;
static constexpr size_t kGlobalChecksum = 0x14E;
};  // namespace cartridge_header_addresses

/**
 * @brief Defines the type of cartridge and any hardware it may use.
 *
 */
enum class CartridgeType : uint8_t {
    kRomOnly = 0x00,
    kMBC1 = 0x01,
    kMBC1Ram = 0x02,
    kMBC1RamBattery = 0x03,
    kMBC2 = 0x05,
    kMBC2Battery = 0x06,
    kRomRam = 0x08,
    kRomRamBattery = 0x09,
    kMMM01 = 0x0B,
    kMMM01Ram = 0x0C,
    kMMM01RamBattery = 0x0D,
    kMBC3TimerBattery = 0x0F,
    kMBC3TimerRamBattery = 0x10,
    kMBC3 = 0x11,
    kMBC3Ram = 0x12,
    kMBC3RamBattery = 0x13,
    kMBC5 = 0x19,
    kMBC5Ram = 0x1A,
    kMBC5RamBattery = 0x1B,
    kMBC5Rumble = 0x1C,
    kMBC5RumbleRam = 0x1D,
    kMBC5RumbleRamBattery = 0x1E,
    kMBC6 = 0x20,
    kMBC7SensorRumbleRamBattery = 0x22,
    kPocketCamera = 0xFC,
    kBandaiTama5 = 0xFD,
    kHuC3 = 0xFE,
    kHuC1RamBattery = 0xFF,
};

/**
 * @brief Defines cartridge codes for defining ROM size.
 *
 */
enum class RomSize : uint8_t {
    kKb32 = 0x00,
    kKb64 = 0x01,
    kKb128 = 0x02,
    kKb256 = 0x03,
    kKb512 = 0x04,
    kMb1 = 0x05,
    kMb2 = 0x06,
    kMb4 = 0x07,
    kMb8 = 0x08,
    kMb11 = 0x52,
    kMb12 = 0x53,
    kMb15 = 0x54,
};

/**
 * @brief Defines cartridge codes for defining RAM size.
 *
 */
enum class RamSize : uint8_t {
    kNone = 0x00,
    kUnused = 0x01,
    kKb8 = 0x02,
    kKb32 = 0x03,
    kKb128 = 0x04,
    kKb64 = 0x05,
};

extern const std::unordered_map<CartridgeType, std::string> kCartridgeTypeToString;
extern const std::unordered_map<RomSize, std::string> kRomSizeToString;
extern const std::unordered_map<RamSize, std::string> kRamSizeToString;
extern const std::unordered_map<RomSize, size_t> kRomSizeToNumBanks;
extern const std::unordered_map<RamSize, size_t> kRamSizeToNumBanks;

/**
 * @brief Cartridge header information.
 *
 */
struct CartridgeHeader {
    std::string title;             // Cartridge title
    uint8_t cgb_flag;              // Gameboy Color support flag
    uint8_t sgb_flag;              // Super Gameboy support flag
    CartridgeType cartridge_type;  // Cartridge MBC type
    RomSize rom_size;              // ROM size
    RamSize ram_size;              // RAM size
    uint8_t destination_code;      // Destination code
};

/**
 * @brief Defines the Gameboy's cartridge.
 *
 * Provides the ability to load and read cartridge data from a file. This also emulates the MBC chip and should be
 * included in the MMU.
 *
 */
class Cartridge final : public MMUModule {
   public:
    Cartridge() = delete;
    explicit Cartridge(const std::filesystem::path& rom_path);

    ~Cartridge() {}

    uint8_t Read(size_t addr) const override;
    void Write(size_t addr, uint8_t val) override;

   private:
    std::vector<uint8_t> m_data;  // Cartridge ROM
    std::vector<uint8_t> m_sram;  // Cartridge SRAM
    CartridgeHeader m_header;
    std::unique_ptr<MBC> m_mbc;  // Memory bank controller

    CartridgeHeader ReadCartridgeHeader();
    std::unique_ptr<MBC> GetMBC(CartridgeType type);
};