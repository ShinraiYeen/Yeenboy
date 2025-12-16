# Yeenboy
An in-development Gameboy emulator written in C++. Hopefully it's fast, I dunno.

## Compiling From Source
1. Clone the repository (recursively, so that submodules are cloned as well)
    ```shell
    git clone --recursive https://github.com/ShinraiYeen/Yeenboy.git
    ```

2. Install required dependencies.
    ```shell
    sudo apt install libsdl2-dev build-essential cmake
    ```

3. Build the project.
    ```shell
    cd Yeenboy
    mkdir -p build && cd build
    cmake ..
    make -j
    ```

4. (Optional) Run the unit tests to confirm everything is working properly.
    ```shell
    ctest
    ```

## Architecture Diagram
```mermaid
classDiagram
    class CPU {
        -m_mem: MemoryBus&

        -m_a: Register~uint8_t~
        -m_b: Register~uint8_t~
        -m_c: Register~uint8_t~
        -m_d: Register~uint8_t~
        -m_e: Register~uint8_t~
        -m_h: Register~uint8_t~
        -m_l: Register~uint8_t~
        -m_f: FlagRegister
        -m_af: PairRegister
        -m_bc: PairRegister
        -m_de: PairRegister
        -m_hl: PairRegister

        -m_sp: Register~uint16_t~

    }

    class Register~T~ {
        +Value(): T
        +Set()

        -m_val: T
    }

    class PairRegister {
        +Value(): uint16_t
        +Set(val)

        -m_high: Register&
        -m_low: Register&
    }

    class FlagRegister {
        +Zero(): bool
        +Subtract(): bool
        +HalfCarry(): bool
        +Carry(): bool

        +SetZero(set)
        +SetSubtract(set)
        +SetHalfCarry(set)
        +SetCarry(set)
    }

    class CartridgeHeader {
        +title: string
        +cgb_flag: uint8_t
        +sgb_flag: uint8_t
        +cartridge_type: CartridgeType
        +rom_size: RomSize
        +ram_size: RamSize
        +destination_code: unit8_t
    }

    class RomSize
    class RamSize
    class CartridgeType

    class Cartridge {
        +ReadRom(addr): uint8_t
        +ReadRam(addr): uint8_t
        +WriteRom(addr, val): uint8_t
        +WriteRam(addr, val): uint8_t

        -m_rom: std::vector~uint8_t~
        -m_ram: std::vector~uint8_t~
    }

    class MemoryBus {
        +Read(addr): uint8_t
        +Write(addr, val)
    }

    class Memory {
        +Read(addr): uint8_t
        +Write(addr, val)
    }

    class WRAM {
        +Read(addr): uint8_t
        +Write(addr, val)

        -m_data: std::vector~uint8_t~
    }

    class VRAM {
        +Read(addr): uint8_t
        +Write(addr, val)

        -m_data: std::vector~uint8_t~
    }

    class MBC {
        +ReadRom(addr): uint8_t
        +ReadRam(addr): uint8_t
        +WriteRom(addr, val)
        +WriteRam(addr, val)
    }

    class MBC1 {
    }

    class MBC3
    class MBC5

    WRAM ..|> Memory
    VRAM ..|> Memory


    MemoryBus o-- Cartridge
    MemoryBus o-- WRAM
    MemoryBus o-- VRAM

    CPU o-- MemoryBus
    CPU *-- Register
    CPU *-- PairRegister

    Cartridge *-- MBC
    Cartridge *-- CartridgeHeader

    CartridgeHeader *-- RomSize
    CartridgeHeader *-- RamSize
    CartridgeHeader *-- CartridgeType


    PairRegister o-- Register

    MBC1 ..|> MBC
    MBC3 ..|> MBC
    MBC5 ..|> MBC

    FlagRegister --|> Register
```