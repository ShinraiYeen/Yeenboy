#pragma once

#include <cstdint>

#include "yeenboy/core/memory_bus.hpp"
#include "yeenboy/core/register.hpp"

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

   private:
    MemoryBus& m_mem;  // Memory bus

    // CPU registers
    Register<uint8_t> m_a, m_b, m_c, m_d, m_e, m_h, m_l;  // Standard 8-bit registers
    Register<uint16_t> m_pc;                              // Program counter
    PairRegister m_af, m_bc, m_de, m_hl;                  // Pair registers
    Register<uint16_t> m_sp;                              // Stack pointer
    FlagRegister m_f;                                     // Flag register

    // === General CPU Helpers ===

    void ExecuteOpcode(uint8_t opcode);
    void ExecuteRegularOpcode(uint8_t opcode);
    void ExecuteCbOpcode(uint8_t opcode);

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
};