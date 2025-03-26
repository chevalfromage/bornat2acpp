#ifndef BIT_H
#define BIT_H

#include "Reg8.hpp"

class Bit{
    public:
    Bit(Reg8* myReg8_temp);
    void operator=(bool* boolIn);
    private:
    char charIn;
    Reg8* myReg8;
    char boolArrayToChar(bool arr[8]);
};

#endif