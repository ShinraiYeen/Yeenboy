#include "yeenboy/core/cpu/cpu.hpp"

int CPU::CBOpcode00() { return 0; }
int CPU::CBOpcode01() { return 0; }
int CPU::CBOpcode02() { return 0; }
int CPU::CBOpcode03() { return 0; }
int CPU::CBOpcode04() { return 0; }
int CPU::CBOpcode05() { return 0; }
int CPU::CBOpcode06() { return 0; }
int CPU::CBOpcode07() { return 0; }
int CPU::CBOpcode08() { return 0; }
int CPU::CBOpcode09() { return 0; }
int CPU::CBOpcode0A() { return 0; }
int CPU::CBOpcode0B() { return 0; }
int CPU::CBOpcode0C() { return 0; }
int CPU::CBOpcode0D() { return 0; }
int CPU::CBOpcode0E() { return 0; }
int CPU::CBOpcode0F() { return 0; }

int CPU::CBOpcode10() { return 0; }
int CPU::CBOpcode11() { return 0; }
int CPU::CBOpcode12() { return 0; }
int CPU::CBOpcode13() { return 0; }
int CPU::CBOpcode14() { return 0; }
int CPU::CBOpcode15() { return 0; }
int CPU::CBOpcode16() { return 0; }
int CPU::CBOpcode17() { return 0; }
int CPU::CBOpcode18() { return 0; }
int CPU::CBOpcode19() { return 0; }
int CPU::CBOpcode1A() { return 0; }
int CPU::CBOpcode1B() { return 0; }
int CPU::CBOpcode1C() { return 0; }
int CPU::CBOpcode1D() { return 0; }
int CPU::CBOpcode1E() { return 0; }
int CPU::CBOpcode1F() { return 0; }

int CPU::CBOpcode20() { return 0; }
int CPU::CBOpcode21() { return 0; }
int CPU::CBOpcode22() { return 0; }
int CPU::CBOpcode23() { return 0; }
int CPU::CBOpcode24() { return 0; }
int CPU::CBOpcode25() { return 0; }
int CPU::CBOpcode26() { return 0; }
int CPU::CBOpcode27() { return 0; }
int CPU::CBOpcode28() { return 0; }
int CPU::CBOpcode29() { return 0; }
int CPU::CBOpcode2A() { return 0; }
int CPU::CBOpcode2B() { return 0; }
int CPU::CBOpcode2C() { return 0; }
int CPU::CBOpcode2D() { return 0; }
int CPU::CBOpcode2E() { return 0; }
int CPU::CBOpcode2F() { return 0; }

int CPU::CBOpcode30() { return 0; }
int CPU::CBOpcode31() { return 0; }
int CPU::CBOpcode32() { return 0; }
int CPU::CBOpcode33() { return 0; }
int CPU::CBOpcode34() { return 0; }
int CPU::CBOpcode35() { return 0; }
int CPU::CBOpcode36() { return 0; }
int CPU::CBOpcode37() { return 0; }
int CPU::CBOpcode38() { return 0; }
int CPU::CBOpcode39() { return 0; }
int CPU::CBOpcode3A() { return 0; }
int CPU::CBOpcode3B() { return 0; }
int CPU::CBOpcode3C() { return 0; }
int CPU::CBOpcode3D() { return 0; }
int CPU::CBOpcode3E() { return 0; }
int CPU::CBOpcode3F() { return 0; }

int CPU::CBOpcode40() { return OpcodeBIT(m_b, 0); }
int CPU::CBOpcode41() { return OpcodeBIT(m_c, 0); }
int CPU::CBOpcode42() { return OpcodeBIT(m_d, 0); }
int CPU::CBOpcode43() { return OpcodeBIT(m_e, 0); }
int CPU::CBOpcode44() { return OpcodeBIT(m_h, 0); }
int CPU::CBOpcode45() { return OpcodeBIT(m_l, 0); }
int CPU::CBOpcode46() { return OpcodeBIT(m_hl, 0); }
int CPU::CBOpcode47() { return OpcodeBIT(m_a, 0); }
int CPU::CBOpcode48() { return OpcodeBIT(m_b, 1); }
int CPU::CBOpcode49() { return OpcodeBIT(m_c, 1); }
int CPU::CBOpcode4A() { return OpcodeBIT(m_d, 1); }
int CPU::CBOpcode4B() { return OpcodeBIT(m_e, 1); }
int CPU::CBOpcode4C() { return OpcodeBIT(m_h, 1); }
int CPU::CBOpcode4D() { return OpcodeBIT(m_l, 1); }
int CPU::CBOpcode4E() { return OpcodeBIT(m_hl, 1); }
int CPU::CBOpcode4F() { return OpcodeBIT(m_a, 1); }

int CPU::CBOpcode50() { return OpcodeBIT(m_b, 2); }
int CPU::CBOpcode51() { return OpcodeBIT(m_c, 2); }
int CPU::CBOpcode52() { return OpcodeBIT(m_d, 2); }
int CPU::CBOpcode53() { return OpcodeBIT(m_e, 2); }
int CPU::CBOpcode54() { return OpcodeBIT(m_h, 2); }
int CPU::CBOpcode55() { return OpcodeBIT(m_l, 2); }
int CPU::CBOpcode56() { return OpcodeBIT(m_hl, 2); }
int CPU::CBOpcode57() { return OpcodeBIT(m_a, 2); }
int CPU::CBOpcode58() { return OpcodeBIT(m_b, 3); }
int CPU::CBOpcode59() { return OpcodeBIT(m_c, 3); }
int CPU::CBOpcode5A() { return OpcodeBIT(m_d, 3); }
int CPU::CBOpcode5B() { return OpcodeBIT(m_e, 3); }
int CPU::CBOpcode5C() { return OpcodeBIT(m_h, 3); }
int CPU::CBOpcode5D() { return OpcodeBIT(m_l, 3); }
int CPU::CBOpcode5E() { return OpcodeBIT(m_hl, 3); }
int CPU::CBOpcode5F() { return OpcodeBIT(m_a, 3); }

int CPU::CBOpcode60() { return OpcodeBIT(m_b, 4); }
int CPU::CBOpcode61() { return OpcodeBIT(m_c, 4); }
int CPU::CBOpcode62() { return OpcodeBIT(m_d, 4); }
int CPU::CBOpcode63() { return OpcodeBIT(m_e, 4); }
int CPU::CBOpcode64() { return OpcodeBIT(m_h, 4); }
int CPU::CBOpcode65() { return OpcodeBIT(m_l, 4); }
int CPU::CBOpcode66() { return OpcodeBIT(m_hl, 4); }
int CPU::CBOpcode67() { return OpcodeBIT(m_a, 4); }
int CPU::CBOpcode68() { return OpcodeBIT(m_b, 5); }
int CPU::CBOpcode69() { return OpcodeBIT(m_c, 5); }
int CPU::CBOpcode6A() { return OpcodeBIT(m_d, 5); }
int CPU::CBOpcode6B() { return OpcodeBIT(m_e, 5); }
int CPU::CBOpcode6C() { return OpcodeBIT(m_h, 5); }
int CPU::CBOpcode6D() { return OpcodeBIT(m_l, 5); }
int CPU::CBOpcode6E() { return OpcodeBIT(m_hl, 5); }
int CPU::CBOpcode6F() { return OpcodeBIT(m_a, 5); }

int CPU::CBOpcode70() { return OpcodeBIT(m_b, 6); }
int CPU::CBOpcode71() { return OpcodeBIT(m_c, 6); }
int CPU::CBOpcode72() { return OpcodeBIT(m_d, 6); }
int CPU::CBOpcode73() { return OpcodeBIT(m_e, 6); }
int CPU::CBOpcode74() { return OpcodeBIT(m_h, 6); }
int CPU::CBOpcode75() { return OpcodeBIT(m_l, 6); }
int CPU::CBOpcode76() { return OpcodeBIT(m_hl, 6); }
int CPU::CBOpcode77() { return OpcodeBIT(m_a, 6); }
int CPU::CBOpcode78() { return OpcodeBIT(m_b, 7); }
int CPU::CBOpcode79() { return OpcodeBIT(m_c, 7); }
int CPU::CBOpcode7A() { return OpcodeBIT(m_d, 7); }
int CPU::CBOpcode7B() { return OpcodeBIT(m_e, 7); }
int CPU::CBOpcode7C() { return OpcodeBIT(m_h, 7); }
int CPU::CBOpcode7D() { return OpcodeBIT(m_l, 7); }
int CPU::CBOpcode7E() { return OpcodeBIT(m_hl, 7); }
int CPU::CBOpcode7F() { return OpcodeBIT(m_a, 7); }

int CPU::CBOpcode80() { return OpcodeSetBitTo(m_b, 0, false); }
int CPU::CBOpcode81() { return OpcodeSetBitTo(m_c, 0, false); }
int CPU::CBOpcode82() { return OpcodeSetBitTo(m_d, 0, false); }
int CPU::CBOpcode83() { return OpcodeSetBitTo(m_e, 0, false); }
int CPU::CBOpcode84() { return OpcodeSetBitTo(m_h, 0, false); }
int CPU::CBOpcode85() { return OpcodeSetBitTo(m_l, 0, false); }
int CPU::CBOpcode86() { return OpcodeSetBitTo(m_hl, 0, false); }
int CPU::CBOpcode87() { return OpcodeSetBitTo(m_a, 0, false); }
int CPU::CBOpcode88() { return OpcodeSetBitTo(m_b, 1, false); }
int CPU::CBOpcode89() { return OpcodeSetBitTo(m_c, 1, false); }
int CPU::CBOpcode8A() { return OpcodeSetBitTo(m_d, 1, false); }
int CPU::CBOpcode8B() { return OpcodeSetBitTo(m_e, 1, false); }
int CPU::CBOpcode8C() { return OpcodeSetBitTo(m_h, 1, false); }
int CPU::CBOpcode8D() { return OpcodeSetBitTo(m_l, 1, false); }
int CPU::CBOpcode8E() { return OpcodeSetBitTo(m_hl, 1, false); }
int CPU::CBOpcode8F() { return OpcodeSetBitTo(m_a, 1, false); }

int CPU::CBOpcode90() { return OpcodeSetBitTo(m_b, 2, false); }
int CPU::CBOpcode91() { return OpcodeSetBitTo(m_c, 2, false); }
int CPU::CBOpcode92() { return OpcodeSetBitTo(m_d, 2, false); }
int CPU::CBOpcode93() { return OpcodeSetBitTo(m_e, 2, false); }
int CPU::CBOpcode94() { return OpcodeSetBitTo(m_h, 2, false); }
int CPU::CBOpcode95() { return OpcodeSetBitTo(m_l, 2, false); }
int CPU::CBOpcode96() { return OpcodeSetBitTo(m_hl, 2, false); }
int CPU::CBOpcode97() { return OpcodeSetBitTo(m_a, 2, false); }
int CPU::CBOpcode98() { return OpcodeSetBitTo(m_b, 3, false); }
int CPU::CBOpcode99() { return OpcodeSetBitTo(m_c, 3, false); }
int CPU::CBOpcode9A() { return OpcodeSetBitTo(m_d, 3, false); }
int CPU::CBOpcode9B() { return OpcodeSetBitTo(m_e, 3, false); }
int CPU::CBOpcode9C() { return OpcodeSetBitTo(m_h, 3, false); }
int CPU::CBOpcode9D() { return OpcodeSetBitTo(m_l, 3, false); }
int CPU::CBOpcode9E() { return OpcodeSetBitTo(m_hl, 3, false); }
int CPU::CBOpcode9F() { return OpcodeSetBitTo(m_a, 3, false); }

int CPU::CBOpcodeA0() { return OpcodeSetBitTo(m_b, 4, false); }
int CPU::CBOpcodeA1() { return OpcodeSetBitTo(m_c, 4, false); }
int CPU::CBOpcodeA2() { return OpcodeSetBitTo(m_d, 4, false); }
int CPU::CBOpcodeA3() { return OpcodeSetBitTo(m_e, 4, false); }
int CPU::CBOpcodeA4() { return OpcodeSetBitTo(m_h, 4, false); }
int CPU::CBOpcodeA5() { return OpcodeSetBitTo(m_l, 4, false); }
int CPU::CBOpcodeA6() { return OpcodeSetBitTo(m_hl, 4, false); }
int CPU::CBOpcodeA7() { return OpcodeSetBitTo(m_a, 4, false); }
int CPU::CBOpcodeA8() { return OpcodeSetBitTo(m_b, 5, false); }
int CPU::CBOpcodeA9() { return OpcodeSetBitTo(m_c, 5, false); }
int CPU::CBOpcodeAA() { return OpcodeSetBitTo(m_d, 5, false); }
int CPU::CBOpcodeAB() { return OpcodeSetBitTo(m_e, 5, false); }
int CPU::CBOpcodeAC() { return OpcodeSetBitTo(m_h, 5, false); }
int CPU::CBOpcodeAD() { return OpcodeSetBitTo(m_l, 5, false); }
int CPU::CBOpcodeAE() { return OpcodeSetBitTo(m_hl, 5, false); }
int CPU::CBOpcodeAF() { return OpcodeSetBitTo(m_a, 5, false); }

int CPU::CBOpcodeB0() { return OpcodeSetBitTo(m_b, 6, false); }
int CPU::CBOpcodeB1() { return OpcodeSetBitTo(m_c, 6, false); }
int CPU::CBOpcodeB2() { return OpcodeSetBitTo(m_d, 6, false); }
int CPU::CBOpcodeB3() { return OpcodeSetBitTo(m_e, 6, false); }
int CPU::CBOpcodeB4() { return OpcodeSetBitTo(m_h, 6, false); }
int CPU::CBOpcodeB5() { return OpcodeSetBitTo(m_l, 6, false); }
int CPU::CBOpcodeB6() { return OpcodeSetBitTo(m_hl, 6, false); }
int CPU::CBOpcodeB7() { return OpcodeSetBitTo(m_a, 6, false); }
int CPU::CBOpcodeB8() { return OpcodeSetBitTo(m_b, 7, false); }
int CPU::CBOpcodeB9() { return OpcodeSetBitTo(m_c, 7, false); }
int CPU::CBOpcodeBA() { return OpcodeSetBitTo(m_d, 7, false); }
int CPU::CBOpcodeBB() { return OpcodeSetBitTo(m_e, 7, false); }
int CPU::CBOpcodeBC() { return OpcodeSetBitTo(m_h, 7, false); }
int CPU::CBOpcodeBD() { return OpcodeSetBitTo(m_l, 7, false); }
int CPU::CBOpcodeBE() { return OpcodeSetBitTo(m_hl, 7, false); }
int CPU::CBOpcodeBF() { return OpcodeSetBitTo(m_a, 7, false); }

int CPU::CBOpcodeC0() { return OpcodeSetBitTo(m_b, 0, true); }
int CPU::CBOpcodeC1() { return OpcodeSetBitTo(m_c, 0, true); }
int CPU::CBOpcodeC2() { return OpcodeSetBitTo(m_d, 0, true); }
int CPU::CBOpcodeC3() { return OpcodeSetBitTo(m_e, 0, true); }
int CPU::CBOpcodeC4() { return OpcodeSetBitTo(m_h, 0, true); }
int CPU::CBOpcodeC5() { return OpcodeSetBitTo(m_l, 0, true); }
int CPU::CBOpcodeC6() { return OpcodeSetBitTo(m_hl, 0, true); }
int CPU::CBOpcodeC7() { return OpcodeSetBitTo(m_a, 0, true); }
int CPU::CBOpcodeC8() { return OpcodeSetBitTo(m_b, 1, true); }
int CPU::CBOpcodeC9() { return OpcodeSetBitTo(m_c, 1, true); }
int CPU::CBOpcodeCA() { return OpcodeSetBitTo(m_d, 1, true); }
int CPU::CBOpcodeCB() { return OpcodeSetBitTo(m_e, 1, true); }
int CPU::CBOpcodeCC() { return OpcodeSetBitTo(m_h, 1, true); }
int CPU::CBOpcodeCD() { return OpcodeSetBitTo(m_l, 1, true); }
int CPU::CBOpcodeCE() { return OpcodeSetBitTo(m_hl, 1, true); }
int CPU::CBOpcodeCF() { return OpcodeSetBitTo(m_a, 1, true); }

int CPU::CBOpcodeD0() { return OpcodeSetBitTo(m_b, 2, true); }
int CPU::CBOpcodeD1() { return OpcodeSetBitTo(m_c, 2, true); }
int CPU::CBOpcodeD2() { return OpcodeSetBitTo(m_d, 2, true); }
int CPU::CBOpcodeD3() { return OpcodeSetBitTo(m_e, 2, true); }
int CPU::CBOpcodeD4() { return OpcodeSetBitTo(m_h, 2, true); }
int CPU::CBOpcodeD5() { return OpcodeSetBitTo(m_l, 2, true); }
int CPU::CBOpcodeD6() { return OpcodeSetBitTo(m_hl, 2, true); }
int CPU::CBOpcodeD7() { return OpcodeSetBitTo(m_a, 2, true); }
int CPU::CBOpcodeD8() { return OpcodeSetBitTo(m_b, 3, true); }
int CPU::CBOpcodeD9() { return OpcodeSetBitTo(m_c, 3, true); }
int CPU::CBOpcodeDA() { return OpcodeSetBitTo(m_d, 3, true); }
int CPU::CBOpcodeDB() { return OpcodeSetBitTo(m_e, 3, true); }
int CPU::CBOpcodeDC() { return OpcodeSetBitTo(m_h, 3, true); }
int CPU::CBOpcodeDD() { return OpcodeSetBitTo(m_l, 3, true); }
int CPU::CBOpcodeDE() { return OpcodeSetBitTo(m_hl, 3, true); }
int CPU::CBOpcodeDF() { return OpcodeSetBitTo(m_a, 3, true); }

int CPU::CBOpcodeE0() { return OpcodeSetBitTo(m_b, 4, true); }
int CPU::CBOpcodeE1() { return OpcodeSetBitTo(m_c, 4, true); }
int CPU::CBOpcodeE2() { return OpcodeSetBitTo(m_d, 4, true); }
int CPU::CBOpcodeE3() { return OpcodeSetBitTo(m_e, 4, true); }
int CPU::CBOpcodeE4() { return OpcodeSetBitTo(m_h, 4, true); }
int CPU::CBOpcodeE5() { return OpcodeSetBitTo(m_l, 4, true); }
int CPU::CBOpcodeE6() { return OpcodeSetBitTo(m_hl, 4, true); }
int CPU::CBOpcodeE7() { return OpcodeSetBitTo(m_a, 4, true); }
int CPU::CBOpcodeE8() { return OpcodeSetBitTo(m_b, 5, true); }
int CPU::CBOpcodeE9() { return OpcodeSetBitTo(m_c, 5, true); }
int CPU::CBOpcodeEA() { return OpcodeSetBitTo(m_d, 5, true); }
int CPU::CBOpcodeEB() { return OpcodeSetBitTo(m_e, 5, true); }
int CPU::CBOpcodeEC() { return OpcodeSetBitTo(m_h, 5, true); }
int CPU::CBOpcodeED() { return OpcodeSetBitTo(m_l, 5, true); }
int CPU::CBOpcodeEE() { return OpcodeSetBitTo(m_hl, 5, true); }
int CPU::CBOpcodeEF() { return OpcodeSetBitTo(m_a, 5, true); }

int CPU::CBOpcodeF0() { return OpcodeSetBitTo(m_b, 6, true); }
int CPU::CBOpcodeF1() { return OpcodeSetBitTo(m_c, 6, true); }
int CPU::CBOpcodeF2() { return OpcodeSetBitTo(m_d, 6, true); }
int CPU::CBOpcodeF3() { return OpcodeSetBitTo(m_e, 6, true); }
int CPU::CBOpcodeF4() { return OpcodeSetBitTo(m_h, 6, true); }
int CPU::CBOpcodeF5() { return OpcodeSetBitTo(m_l, 6, true); }
int CPU::CBOpcodeF6() { return OpcodeSetBitTo(m_hl, 6, true); }
int CPU::CBOpcodeF7() { return OpcodeSetBitTo(m_a, 6, true); }
int CPU::CBOpcodeF8() { return OpcodeSetBitTo(m_b, 7, true); }
int CPU::CBOpcodeF9() { return OpcodeSetBitTo(m_c, 7, true); }
int CPU::CBOpcodeFA() { return OpcodeSetBitTo(m_d, 7, true); }
int CPU::CBOpcodeFB() { return OpcodeSetBitTo(m_e, 7, true); }
int CPU::CBOpcodeFC() { return OpcodeSetBitTo(m_h, 7, true); }
int CPU::CBOpcodeFD() { return OpcodeSetBitTo(m_l, 7, true); }
int CPU::CBOpcodeFE() { return OpcodeSetBitTo(m_hl, 7, true); }
int CPU::CBOpcodeFF() { return OpcodeSetBitTo(m_a, 7, true); }