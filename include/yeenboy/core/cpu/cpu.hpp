#pragma once

#include <cstdint>

#include "yeenboy/core/memory_bus.hpp"
#include "yeenboy/core/register.hpp"

// clang-format off
#define GLUE(a, b) a##b
#define JOIN(a, b) GLUE(a, b)

#define HEX_16(item_macro, prefix) \
    item_macro(prefix, 0) item_macro(prefix, 1) item_macro(prefix, 2) item_macro(prefix, 3) \
    item_macro(prefix, 4) item_macro(prefix, 5) item_macro(prefix, 6) item_macro(prefix, 7) \
    item_macro(prefix, 8) item_macro(prefix, 9) item_macro(prefix, A) item_macro(prefix, B) \
    item_macro(prefix, C) item_macro(prefix, D) item_macro(prefix, E) item_macro(prefix, F)

#define HEX_256(item_macro, prefix) \
    HEX_16(item_macro, JOIN(prefix, 0)) HEX_16(item_macro, JOIN(prefix, 1)) \
    HEX_16(item_macro, JOIN(prefix, 2)) HEX_16(item_macro, JOIN(prefix, 3)) \
    HEX_16(item_macro, JOIN(prefix, 4)) HEX_16(item_macro, JOIN(prefix, 5)) \
    HEX_16(item_macro, JOIN(prefix, 6)) HEX_16(item_macro, JOIN(prefix, 7)) \
    HEX_16(item_macro, JOIN(prefix, 8)) HEX_16(item_macro, JOIN(prefix, 9)) \
    HEX_16(item_macro, JOIN(prefix, A)) HEX_16(item_macro, JOIN(prefix, B)) \
    HEX_16(item_macro, JOIN(prefix, C)) HEX_16(item_macro, JOIN(prefix, D)) \
    HEX_16(item_macro, JOIN(prefix, E)) HEX_16(item_macro, JOIN(prefix, F))

#define AS_DECL(prefix, hex) int JOIN(prefix, hex)();
#define AS_MAP(prefix, hex) &CPU::JOIN(prefix, hex),
// clang-format on

/**
 * @brief Defines the Gameboy DMG's CPU.
 *
 */
class CPU {
   public:
    static constexpr unsigned int kTClockSpeedHz = 4194304;             // 4.194304 MHz
    static constexpr unsigned int kMClockSpeedHz = kTClockSpeedHz / 4;  // 1.048576 MHz

    CPU() = delete;
    explicit CPU(MemoryBus& mem);
    ~CPU() = default;

    void Tick();

   private:
    MemoryBus& m_mem;  // Memory bus

    // CPU registers
    Register<uint8_t> m_a, m_b, m_c, m_d, m_e, m_h, m_l;  // Standard 8-bit registers
    Register<uint16_t> m_pc;                              // Program counter
    PairRegister m_af, m_bc, m_de, m_hl;                  // Pair registers
    Register<uint16_t> m_sp;                              // Stack pointer
    FlagRegister m_f;                                     // Flag register

    // CPU flags
    bool m_halt_cpu = false;

    // === General CPU Helpers ===

    void ExecuteOpcode(uint8_t opcode);
    void ExecuteRegularOpcode(uint8_t opcode);
    void ExecuteCbOpcode(uint8_t opcode);

    /**
     * @brief Returns the byte the PC (Program counter) is referring to in memory and increments the PC register.
     *
     * @return The byte being pointed to by the PC register before being incremented.
     */
    uint8_t GetPCByte();

    // === Opcode Helpers ===

    // Misc/control
    int OpcodeNOP();   // No-op
    int OpcodeSTOP();  // Halt CPU
    int OpcodeHALT();  // Halt CPU until interrupt occurs

    // Load and store helpers
    int OpcodeLD(PairRegister& store_addr, Register<uint8_t>& load_reg);      // Write byte register to memory
    int OpcodeLD(Register<uint8_t>& store_reg, PairRegister& load_addr);      // Load from memory into byte register
    int OpcodeLD(Register<uint8_t>& store_reg, Register<uint8_t>& load_reg);  // Copy into other byte register

    // Arithmetic logic unit
    int OpcodeINC(Register<uint8_t>& reg);  // Increment
    int OpcodeDEC(Register<uint8_t>& reg);  // Decrement
    int OpcodeADD(Register<uint8_t>& reg);  // Addition
    int OpcodeSUB(Register<uint8_t>& reg);  // Subtraction
    int OpcodeADC(Register<uint8_t>& reg);  // Addition with carry
    int OpcodeSBC(Register<uint8_t>& reg);  // Subtraction with carry
    int OpcodeAND(Register<uint8_t>& reg);  // Bitwise AND
    int OpcodeXOR(Register<uint8_t>& reg);  // Bitwise XOR
    int OpcodeOR(Register<uint8_t>& reg);   // Bitwise OR
    int OpcodeCP(Register<uint8_t>& reg);   // Comparison

    // Stack operations
    int OpcodePOP(PairRegister& reg);   // Stack POP
    int OpcodePUSH(PairRegister& reg);  // Stack PUSH

    // Rotates and shifts
    int OpcodeRCLA();
    int OpcodeRLA();
    int OpcodeRRCA();
    int OpcodeRLC(Register<uint8_t>& reg);
    int OpcodeRL(Register<uint8_t>& reg);
    int OpcodeRRC(Register<uint8_t>& reg);
    int OpcodeRR(Register<uint8_t>& reg);
    int OpcodeSLA(Register<uint8_t>& reg);
    int OpcodeSRA(Register<uint8_t>& reg);
    int OpcodeSRL(Register<uint8_t>& reg);

    // Branching

    // Misc
    int OpcodeDI();    // Disable interrupts
    int OpcodeEI();    // Enable interrupts
    int OpcodeSWAP();  // Swap nibbles

    // === Opcode Mapping Tables ===

    // NOLINTBEGIN
    HEX_256(AS_DECL, Opcode)
    HEX_256(AS_DECL, CBOpcode)
    // NOLINTEND

    using OpcodeSignature = int (CPU::*)();
    static constexpr std::array<OpcodeSignature, 256> kOpcodeMap = {HEX_256(AS_MAP, Opcode)};  // Regular opcode table
    static constexpr std::array<OpcodeSignature, 256> kCBOpcodeMap = {HEX_256(AS_MAP, CBOpcode)};  // CB opcode table
};

// Avoid polluting the namespace
#undef GLUE
#undef JOIN
#undef HEX_16
#undef HEX_256
#undef AS_DECL
#undef AS_MAP