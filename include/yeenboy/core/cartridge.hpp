#pragma once

#include <filesystem>
#include <unordered_map>
#include <vector>

/**
 * @brief Defines addresses for cartridge header information.
 *
 */
namespace CartridgeHeaderAddresses {
static constexpr size_t TITLE_START = 0x134;
static constexpr size_t TITLE_END = 0x143;
static constexpr size_t MANUFACTURER_CODE = 0x13F;
static constexpr size_t CGB_FLAG = 0x143;
static constexpr size_t SGB_FLAG = 0x146;
static constexpr size_t CARTRIDGE_TYPE = 0x147;
static constexpr size_t ROM_SIZE = 0x148;
static constexpr size_t RAM_SIZE = 0x149;
static constexpr size_t DESTINATION_CODE = 0x14A;
static constexpr size_t OLD_LICENSEE_CODE = 0x14B;
static constexpr size_t MASK_ROM_VERSION_NUMBER = 0x14C;
static constexpr size_t HEADER_CHECKSUM = 0x14D;
static constexpr size_t GLOBAL_CHECKSUM = 0x14E;
};  // namespace CartridgeHeaderAddresses

/**
 * @brief Defines the type of cartridge and any hardware it may use.
 *
 */
enum class CartridgeType : uint8_t {
    ROM_ONLY = 0x00,
    MBC1 = 0x01,
    MBC1_RAM = 0x02,
    MBC1_RAM_BATTERY = 0x03,
    MBC2 = 0x05,
    MBC2_BATTERY = 0x06,
    ROM_RAM = 0x08,
    ROM_RAM_BATTERY = 0x09,
    MMM01 = 0x0B,
    MMM01_RAM = 0x0C,
    MMM01_RAM_BATTERY = 0x0D,
    MBC3_TIMER_BATTERY = 0x0F,
    MBC3_TIMER_RAM_BATTERY = 0x10,
    MBC3 = 0x11,
    MBC3_RAM = 0x12,
    MBC3_RAM_BATTERY = 0x13,
    MBC5 = 0x19,
    MBC5_RAM = 0x1A,
    MBC5_RAM_BATTERY = 0x1B,
    MBC5_RUMBLE = 0x1C,
    MBC5_RUMBLE_RAM = 0x1D,
    MBC5_RUMBLE_RAM_BATTERY = 0x1E,
    MBC6 = 0x20,
    MBC7_SENSOR_RUMBLE_RAM_BATTERY = 0x22,
    POCKET_CAMERA = 0xFC,
    BANDAI_TAMA5 = 0xFD,
    HuC3 = 0xFE,
    HuC1_RAM_BATTERY = 0xFF,
};

/**
 * @brief Defines cartridge codes for defining ROM size.
 *
 */
enum class RomSize : uint8_t {
    KB_32 = 0x00,
    KB_64 = 0x01,
    KB_128 = 0x02,
    KB_256 = 0x03,
    KB_512 = 0x04,
    MB_1 = 0x05,
    MB_2 = 0x06,
    MB_4 = 0x07,
    MB_8 = 0x08,
    MB_1_1 = 0x52,
    MB_1_2 = 0x53,
    MB_1_5 = 0x54,
};

/**
 * @brief Defines cartridge codes for defining RAM size.
 *
 */
enum class RamSize : uint8_t {
    NONE = 0x00,
    UNUSED = 0x01,
    KB_8 = 0x02,
    KB_32 = 0x03,
    KB_128 = 0x04,
    KB_64 = 0x05,
};

extern const std::unordered_map<CartridgeType, std::string> kCartridgeTypeToString;
extern const std::unordered_map<RomSize, std::string> kRomSizeToString;
extern const std::unordered_map<RamSize, std::string> kRamSizeToString;

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
class Cartridge {
   public:
    Cartridge() = delete;
    Cartridge(const std::filesystem::path rom_path);

    ~Cartridge() = default;

   private:
    std::vector<uint8_t> m_data;  // Cartridge data
    CartridgeHeader m_header;

    CartridgeHeader ReadCartridgeHeader();
};