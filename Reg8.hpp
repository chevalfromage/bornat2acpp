#ifndef REG8_H
#define REG8_H

#include <unistd.h> 
#include "mx3_board.hpp"
#include "Bit.hpp"

class Reg8{
public:
    Reg8(MX3board* temp_board, unsigned char temp_addr);
    MX3board* board;
    int tty;
    unsigned char addr;
    void operator=(unsigned char data);
    operator unsigned char();
    bool operator[](int indice);
   
};
#else

class Reg8;

#endif