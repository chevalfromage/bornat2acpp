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
    for (int i = 7; i >= 0; --i) {  // On commence par le bit de poids fort (bit 7)
        bool_entier[i] = (char_entier & 1);  // Vérifie si le bit le plus à droite est 1 ou 0
        char_entier >>= 1;  // Décale c d'un bit vers la droite pour examiner le bit suivant
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
    return boolIn;
}