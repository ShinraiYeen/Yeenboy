#pragma once

#include "yeenboy/common/types.hpp"
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
    Register<u8> m_a, m_b, m_c, m_d, m_e, m_h, m_l;  // Standard 8-bit registers
    Register<u16> m_pc;                              // Program counter
    PairRegister m_af, m_bc, m_de, m_hl;             // Pair registers
    Register<u16> m_sp;                              // Stack pointer
    FlagRegister m_f;                                // Flag register

    // CPU flags
    bool m_halt_cpu = false;

    // === General CPU Helpers ===

    void ExecuteOpcode(u8 opcode);
    void ExecuteRegularOpcode(u8 opcode);
    void ExecuteCbOpcode(u8 opcode);

    /**
     * @brief Returns the byte the PC (Program counter) is referring to in memory and increments the PC register.
     *
     * @return The byte being pointed to by the PC register before being incremented.
     */
    u8 GetPCByte();

    // === Opcode Helpers ===

    // Misc/control
    int OpcodeNOP();   // No-op
    int OpcodeSTOP();  // Halt CPU
    int OpcodeHALT();  // Halt CPU until interrupt occurs

    // Load and store helpers
    int OpcodeLD(PairRegister& store_addr, Register<u8>& load_reg);  // Write byte register to memory
    int OpcodeLD(Register<u8>& store_reg, PairRegister& load_addr);  // Load from memory into byte register
    int OpcodeLD(Register<u8>& store_reg, Register<u8>& load_reg);   // Copy into other byte register

    // Arithmetic logic unit
    int OpcodeINC(Register<u8>& reg);  // Increment
    int OpcodeDEC(Register<u8>& reg);  // Decrement
    int OpcodeADD(Register<u8>& reg);  // Addition
    int OpcodeSUB(Register<u8>& reg);  // Subtraction
    int OpcodeADC(Register<u8>& reg);  // Addition with carry
    int OpcodeSBC(Register<u8>& reg);  // Subtraction with carry
    int OpcodeAND(Register<u8>& reg);  // Bitwise AND
    int OpcodeXOR(Register<u8>& reg);  // Bitwise XOR
    int OpcodeOR(Register<u8>& reg);   // Bitwise OR
    int OpcodeCP(Register<u8>& reg);   // Comparison

    // Stack operations
    int OpcodePOP(PairRegister& reg);   // Stack POP
    int OpcodePUSH(PairRegister& reg);  // Stack PUSH

    // Rotates and shifts
    int OpcodeRCLA();
    int OpcodeRLA();
    int OpcodeRRCA();
    int OpcodeRLC(Register<u8>& reg);
    int OpcodeRL(Register<u8>& reg);
    int OpcodeRRC(Register<u8>& reg);
    int OpcodeRR(Register<u8>& reg);
    int OpcodeSLA(Register<u8>& reg);
    int OpcodeSRA(Register<u8>& reg);
    int OpcodeSRL(Register<u8>& reg);

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