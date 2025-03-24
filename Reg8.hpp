#ifndef REG8_H
#define REG8_H

#include "mx3_board.hpp"
#include <unistd.h> 

class Reg8{
    public:
    Reg8(MX3board& temp_board, unsigned char temp_addr);
    MX3board& board;
    int tty = board.tty;
    unsigned char addr_led;
    void operator=(unsigned char data);
    operator unsigned char();
};

#endif