#include "Bit.hpp"

Bit::Bit(Reg8* myReg8_temp, const int bit_addr_temp){
    myReg8 = myReg8_temp;
    bit_addr = 7-bit_addr_temp;
}

void Bit::operator=(bool boolIn_temp){
    boolIn = boolIn_temp;
    char_entier = *myReg8;
    this->charToBoolArray();
    bool_entier[bit_addr]=boolIn;
    this->boolArrayToChar();
    *myReg8 = char_entier;
}

void Bit::charToBoolArray() {
    for (int i = 7; i >= 0; --i) {
        bool_entier[i] = (char_entier & 1);
        char_entier >>= 1;
    }
}

void Bit::boolArrayToChar() {
    char_entier = 0;
    for (int i = 0; i < 8; ++i) {
        char_entier <<= 1;
        if (bool_entier[i]) {
            char_entier |= 1;
        }
    }
}

Bit::operator bool(){
    char_entier = *myReg8;
    this->charToBoolArray();
    bool res = bool_entier[bit_addr];
    return res;
}