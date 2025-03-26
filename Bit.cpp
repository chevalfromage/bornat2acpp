#include "Bit.hpp"

Bit::Bit(Reg8* myReg8_temp){
    myReg8 = myReg8_temp;
}

void Bit::operator=(bool* boolIn){
    charIn = this->boolArrayToChar(boolIn);
    *myReg8 = charIn;
}

char Bit::boolArrayToChar(bool arr[8]) {
    char result = 0;
    for (int i = 0; i < 8; ++i) {
        result <<= 1;
        if (arr[i]) {
            result |= 1;
        }
    }

    return result;
}