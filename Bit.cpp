#include "Bit.hpp"

Bit::Bit(Reg8* myReg8_temp, const int bit_addr_temp){
    myReg8 = myReg8_temp;
    bit_addr = bit_addr_temp;
}

void Bit::operator=(bool boolIn_temp){
    boolIn = boolIn_temp;
    char_entier = *myReg8;
    this->charToBoolArray(char_entier);
    bool_entier[bit_addr]=boolIn;
    this->boolArrayToChar(bool_entier);
    *myReg8 = charIn;
}

void Bit::charToBoolArray(char c) {
    for (int i = 7; i >= 0; --i) {  // On commence par le bit de poids fort (bit 7)
        bool_entier[i] = (c & 1);  // Vérifie si le bit le plus à droite est 1 ou 0
        c >>= 1;  // Décale c d'un bit vers la droite pour examiner le bit suivant
    }
}

void Bit::boolArrayToChar(bool arr[8]) {
    char_entier = 0;
    for (int i = 0; i < 8; ++i) {
        char_entier <<= 1;
        if (arr[i]) {
            char_entier |= 1;
        }
    }
}

Bit::operator bool(){
    return boolIn;
}