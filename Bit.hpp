#ifndef BIT_H
#define BIT_H

#include "Reg8.hpp"

class Bit{
public:
    Bit(Reg8* myReg8_temp, const int bit_addr_temp);
    void operator=(bool boolIn_temp);
    operator bool();
private:
    int bit_addr;
    unsigned char char_entier;
    bool bool_entier[8];
    bool boolIn;
    char charIn;
    Reg8* myReg8;
    void boolArrayToChar();
    void charToBoolArray();
};

#endif