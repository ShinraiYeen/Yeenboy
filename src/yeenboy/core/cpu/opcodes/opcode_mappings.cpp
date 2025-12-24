#include "yeenboy/core/cpu/cpu.hpp"

int CPU::Opcode00() { return OpcodeNOP(); }
int CPU::Opcode01() { return OpcodeLD(m_bc); }
int CPU::Opcode02() { return OpcodeLD(m_bc, m_a); }
int CPU::Opcode03() { return 0; }
int CPU::Opcode04() { return OpcodeINC(m_b); }
int CPU::Opcode05() { return OpcodeDEC(m_b); }
int CPU::Opcode06() { return OpcodeLD(m_b); }
int CPU::Opcode07() { return 0; }
int CPU::Opcode08() { return 0; }
int CPU::Opcode09() { return 0; }
int CPU::Opcode0A() { return 0; }
int CPU::Opcode0B() { return 0; }
int CPU::Opcode0C() { return 0; }
int CPU::Opcode0D() { return 0; }
int CPU::Opcode0E() { return 0; }
int CPU::Opcode0F() { return 0; }

int CPU::Opcode10() { return 0; }
int CPU::Opcode11() { return 0; }
int CPU::Opcode12() { return 0; }
int CPU::Opcode13() { return 0; }
int CPU::Opcode14() { return 0; }
int CPU::Opcode15() { return 0; }
int CPU::Opcode16() { return 0; }
int CPU::Opcode17() { return 0; }
int CPU::Opcode18() { return OpcodeJR(); }
int CPU::Opcode19() { return 0; }
int CPU::Opcode1A() { return 0; }
int CPU::Opcode1B() { return 0; }
int CPU::Opcode1C() { return 0; }
int CPU::Opcode1D() { return 0; }
int CPU::Opcode1E() { return 0; }
int CPU::Opcode1F() { return 0; }

int CPU::Opcode20() { return OpcodeJR(!m_f.Zero()); }
int CPU::Opcode21() { return 0; }
int CPU::Opcode22() { return 0; }
int CPU::Opcode23() { return 0; }
int CPU::Opcode24() { return 0; }
int CPU::Opcode25() { return 0; }
int CPU::Opcode26() { return 0; }
int CPU::Opcode27() { return 0; }
int CPU::Opcode28() { return OpcodeJR(m_f.Zero()); }
int CPU::Opcode29() { return 0; }
int CPU::Opcode2A() { return 0; }
int CPU::Opcode2B() { return 0; }
int CPU::Opcode2C() { return 0; }
int CPU::Opcode2D() { return 0; }
int CPU::Opcode2E() { return 0; }
int CPU::Opcode2F() { return 0; }

int CPU::Opcode30() { return OpcodeJR(!m_f.Carry()); }
int CPU::Opcode31() { return 0; }
int CPU::Opcode32() { return 0; }
int CPU::Opcode33() { return 0; }
int CPU::Opcode34() { return 0; }
int CPU::Opcode35() { return 0; }
int CPU::Opcode36() { return 0; }
int CPU::Opcode37() { return 0; }
int CPU::Opcode38() { return OpcodeJR(m_f.Carry()); }
int CPU::Opcode39() { return 0; }
int CPU::Opcode3A() { return 0; }
int CPU::Opcode3B() { return 0; }
int CPU::Opcode3C() { return 0; }
int CPU::Opcode3D() { return 0; }
int CPU::Opcode3E() { return 0; }
int CPU::Opcode3F() { return 0; }

int CPU::Opcode40() { return OpcodeLD(m_b, m_b); }
int CPU::Opcode41() { return OpcodeLD(m_b, m_c); }
int CPU::Opcode42() { return OpcodeLD(m_b, m_d); }
int CPU::Opcode43() { return OpcodeLD(m_b, m_e); }
int CPU::Opcode44() { return OpcodeLD(m_b, m_h); }
int CPU::Opcode45() { return OpcodeLD(m_b, m_l); }
int CPU::Opcode46() { return OpcodeLD(m_b, m_hl); }
int CPU::Opcode47() { return OpcodeLD(m_b, m_a); }
int CPU::Opcode48() { return OpcodeLD(m_c, m_b); }
int CPU::Opcode49() { return OpcodeLD(m_c, m_c); }
int CPU::Opcode4A() { return OpcodeLD(m_c, m_d); }
int CPU::Opcode4B() { return OpcodeLD(m_c, m_e); }
int CPU::Opcode4C() { return OpcodeLD(m_c, m_h); }
int CPU::Opcode4D() { return OpcodeLD(m_c, m_l); }
int CPU::Opcode4E() { return OpcodeLD(m_c, m_hl); }
int CPU::Opcode4F() { return OpcodeLD(m_c, m_a); }

int CPU::Opcode50() { return OpcodeLD(m_d, m_b); }
int CPU::Opcode51() { return OpcodeLD(m_d, m_c); }
int CPU::Opcode52() { return OpcodeLD(m_d, m_d); }
int CPU::Opcode53() { return OpcodeLD(m_d, m_e); }
int CPU::Opcode54() { return OpcodeLD(m_d, m_h); }
int CPU::Opcode55() { return OpcodeLD(m_d, m_l); }
int CPU::Opcode56() { return OpcodeLD(m_d, m_hl); }
int CPU::Opcode57() { return OpcodeLD(m_d, m_a); }
int CPU::Opcode58() { return OpcodeLD(m_e, m_b); }
int CPU::Opcode59() { return OpcodeLD(m_e, m_c); }
int CPU::Opcode5A() { return OpcodeLD(m_e, m_d); }
int CPU::Opcode5B() { return OpcodeLD(m_e, m_e); }
int CPU::Opcode5C() { return OpcodeLD(m_e, m_h); }
int CPU::Opcode5D() { return OpcodeLD(m_e, m_l); }
int CPU::Opcode5E() { return OpcodeLD(m_e, m_hl); }
int CPU::Opcode5F() { return OpcodeLD(m_e, m_a); }

int CPU::Opcode60() { return OpcodeLD(m_h, m_b); }
int CPU::Opcode61() { return OpcodeLD(m_h, m_c); }
int CPU::Opcode62() { return OpcodeLD(m_h, m_d); }
int CPU::Opcode63() { return OpcodeLD(m_h, m_e); }
int CPU::Opcode64() { return OpcodeLD(m_h, m_h); }
int CPU::Opcode65() { return OpcodeLD(m_h, m_l); }
int CPU::Opcode66() { return OpcodeLD(m_h, m_hl); }
int CPU::Opcode67() { return OpcodeLD(m_h, m_a); }
int CPU::Opcode68() { return OpcodeLD(m_l, m_b); }
int CPU::Opcode69() { return OpcodeLD(m_l, m_c); }
int CPU::Opcode6A() { return OpcodeLD(m_l, m_d); }
int CPU::Opcode6B() { return OpcodeLD(m_l, m_e); }
int CPU::Opcode6C() { return OpcodeLD(m_l, m_h); }
int CPU::Opcode6D() { return OpcodeLD(m_l, m_l); }
int CPU::Opcode6E() { return OpcodeLD(m_l, m_hl); }
int CPU::Opcode6F() { return OpcodeLD(m_l, m_a); }

int CPU::Opcode70() { return OpcodeLD(m_hl, m_b); }
int CPU::Opcode71() { return OpcodeLD(m_hl, m_c); }
int CPU::Opcode72() { return OpcodeLD(m_hl, m_d); }
int CPU::Opcode73() { return OpcodeLD(m_hl, m_e); }
int CPU::Opcode74() { return OpcodeLD(m_hl, m_h); }
int CPU::Opcode75() { return OpcodeLD(m_hl, m_l); }
int CPU::Opcode76() { return OpcodeHALT(); }
int CPU::Opcode77() { return OpcodeLD(m_hl, m_a); }
int CPU::Opcode78() { return OpcodeLD(m_a, m_b); }
int CPU::Opcode79() { return OpcodeLD(m_a, m_c); }
int CPU::Opcode7A() { return OpcodeLD(m_a, m_d); }
int CPU::Opcode7B() { return OpcodeLD(m_a, m_e); }
int CPU::Opcode7C() { return OpcodeLD(m_a, m_h); }
int CPU::Opcode7D() { return OpcodeLD(m_a, m_l); }
int CPU::Opcode7E() { return OpcodeLD(m_a, m_hl); }
int CPU::Opcode7F() { return OpcodeLD(m_a, m_a); }

int CPU::Opcode80() { return OpcodeADD(m_b); }
int CPU::Opcode81() { return OpcodeADD(m_c); }
int CPU::Opcode82() { return OpcodeADD(m_d); }
int CPU::Opcode83() { return OpcodeADD(m_e); }
int CPU::Opcode84() { return OpcodeADD(m_h); }
int CPU::Opcode85() { return OpcodeADD(m_l); }
int CPU::Opcode86() { return OpcodeADD(m_hl); }
int CPU::Opcode87() { return OpcodeADD(m_a); }
int CPU::Opcode88() { return OpcodeADC(m_b); }
int CPU::Opcode89() { return OpcodeADC(m_c); }
int CPU::Opcode8A() { return OpcodeADC(m_d); }
int CPU::Opcode8B() { return OpcodeADC(m_e); }
int CPU::Opcode8C() { return OpcodeADC(m_h); }
int CPU::Opcode8D() { return OpcodeADC(m_l); }
int CPU::Opcode8E() { return OpcodeADC(m_hl); }
int CPU::Opcode8F() { return OpcodeADC(m_a); }

int CPU::Opcode90() { return OpcodeSUB(m_b); }
int CPU::Opcode91() { return OpcodeSUB(m_c); }
int CPU::Opcode92() { return OpcodeSUB(m_d); }
int CPU::Opcode93() { return OpcodeSUB(m_e); }
int CPU::Opcode94() { return OpcodeSUB(m_h); }
int CPU::Opcode95() { return OpcodeSUB(m_l); }
int CPU::Opcode96() { return OpcodeSUB(m_hl); }
int CPU::Opcode97() { return OpcodeSUB(m_a); }
int CPU::Opcode98() { return OpcodeSBC(m_b); }
int CPU::Opcode99() { return OpcodeSBC(m_c); }
int CPU::Opcode9A() { return OpcodeSBC(m_d); }
int CPU::Opcode9B() { return OpcodeSBC(m_e); }
int CPU::Opcode9C() { return OpcodeSBC(m_h); }
int CPU::Opcode9D() { return OpcodeSBC(m_l); }
int CPU::Opcode9E() { return OpcodeSBC(m_hl); }
int CPU::Opcode9F() { return OpcodeSBC(m_a); }

int CPU::OpcodeA0() { return OpcodeAND(m_b); }
int CPU::OpcodeA1() { return OpcodeAND(m_c); }
int CPU::OpcodeA2() { return OpcodeAND(m_d); }
int CPU::OpcodeA3() { return OpcodeAND(m_e); }
int CPU::OpcodeA4() { return OpcodeAND(m_h); }
int CPU::OpcodeA5() { return OpcodeAND(m_l); }
int CPU::OpcodeA6() { return OpcodeAND(m_hl); }
int CPU::OpcodeA7() { return OpcodeAND(m_a); }
int CPU::OpcodeA8() { return OpcodeXOR(m_b); }
int CPU::OpcodeA9() { return OpcodeXOR(m_c); }
int CPU::OpcodeAA() { return OpcodeXOR(m_d); }
int CPU::OpcodeAB() { return OpcodeXOR(m_e); }
int CPU::OpcodeAC() { return OpcodeXOR(m_h); }
int CPU::OpcodeAD() { return OpcodeXOR(m_l); }
int CPU::OpcodeAE() { return OpcodeXOR(m_hl); }
int CPU::OpcodeAF() { return OpcodeXOR(m_a); }

int CPU::OpcodeB0() { return OpcodeOR(m_b); }
int CPU::OpcodeB1() { return OpcodeOR(m_c); }
int CPU::OpcodeB2() { return OpcodeOR(m_d); }
int CPU::OpcodeB3() { return OpcodeOR(m_e); }
int CPU::OpcodeB4() { return OpcodeOR(m_h); }
int CPU::OpcodeB5() { return OpcodeOR(m_l); }
int CPU::OpcodeB6() { return OpcodeOR(m_hl); }
int CPU::OpcodeB7() { return OpcodeOR(m_a); }
int CPU::OpcodeB8() { return OpcodeCP(m_b); }
int CPU::OpcodeB9() { return OpcodeCP(m_c); }
int CPU::OpcodeBA() { return OpcodeCP(m_d); }
int CPU::OpcodeBB() { return OpcodeCP(m_e); }
int CPU::OpcodeBC() { return OpcodeCP(m_h); }
int CPU::OpcodeBD() { return OpcodeCP(m_l); }
int CPU::OpcodeBE() { return OpcodeCP(m_hl); }
int CPU::OpcodeBF() { return OpcodeCP(m_a); }

int CPU::OpcodeC0() { return 0; }
int CPU::OpcodeC1() { return 0; }
int CPU::OpcodeC2() { return OpcodeJP(!m_f.Zero()); }
int CPU::OpcodeC3() { return OpcodeJP(); }
int CPU::OpcodeC4() { return 0; }
int CPU::OpcodeC5() { return 0; }
int CPU::OpcodeC6() { return OpcodeADD(); }
int CPU::OpcodeC7() { return 0; }
int CPU::OpcodeC8() { return 0; }
int CPU::OpcodeC9() { return 0; }
int CPU::OpcodeCA() { return OpcodeJP(m_f.Zero()); }
int CPU::OpcodeCB() { return 0; }
int CPU::OpcodeCC() { return 0; }
int CPU::OpcodeCD() { return 0; }
int CPU::OpcodeCE() { return OpcodeADC(); }
int CPU::OpcodeCF() { return 0; }

int CPU::OpcodeD0() { return 0; }
int CPU::OpcodeD1() { return 0; }
int CPU::OpcodeD2() { return OpcodeJP(!m_f.Carry()); }
int CPU::OpcodeD3() { return OpcodeILLEGAL(); }
int CPU::OpcodeD4() { return 0; }
int CPU::OpcodeD5() { return 0; }
int CPU::OpcodeD6() { return OpcodeSUB(); }
int CPU::OpcodeD7() { return 0; }
int CPU::OpcodeD8() { return 0; }
int CPU::OpcodeD9() { return 0; }
int CPU::OpcodeDA() { return OpcodeJP(m_f.Carry()); }
int CPU::OpcodeDB() { return OpcodeILLEGAL(); }
int CPU::OpcodeDC() { return 0; }
int CPU::OpcodeDD() { return OpcodeILLEGAL(); }
int CPU::OpcodeDE() { return OpcodeSBC(); }
int CPU::OpcodeDF() { return 0; }

int CPU::OpcodeE0() { return 0; }
int CPU::OpcodeE1() { return 0; }
int CPU::OpcodeE2() { return 0; }
int CPU::OpcodeE3() { return OpcodeILLEGAL(); }
int CPU::OpcodeE4() { return OpcodeILLEGAL(); }
int CPU::OpcodeE5() { return 0; }
int CPU::OpcodeE6() { return OpcodeAND(); }
int CPU::OpcodeE7() { return 0; }
int CPU::OpcodeE8() { return 0; }
int CPU::OpcodeE9() { return OpcodeJP(m_hl); }
int CPU::OpcodeEA() { return 0; }
int CPU::OpcodeEB() { return OpcodeILLEGAL(); }
int CPU::OpcodeEC() { return OpcodeILLEGAL(); }
int CPU::OpcodeED() { return OpcodeILLEGAL(); }
int CPU::OpcodeEE() { return OpcodeXOR(); }
int CPU::OpcodeEF() { return 0; }

int CPU::OpcodeF0() { return 0; }
int CPU::OpcodeF1() { return 0; }
int CPU::OpcodeF2() { return 0; }
int CPU::OpcodeF3() { return 0; }
int CPU::OpcodeF4() { return OpcodeILLEGAL(); }
int CPU::OpcodeF5() { return 0; }
int CPU::OpcodeF6() { return OpcodeOR(); }
int CPU::OpcodeF7() { return 0; }
int CPU::OpcodeF8() { return 0; }
int CPU::OpcodeF9() { return 0; }
int CPU::OpcodeFA() { return 0; }
int CPU::OpcodeFB() { return 0; }
int CPU::OpcodeFC() { return OpcodeILLEGAL(); }
int CPU::OpcodeFD() { return OpcodeILLEGAL(); }
int CPU::OpcodeFE() { return OpcodeCP(); }
int CPU::OpcodeFF() { return 0; }