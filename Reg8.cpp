#include "Reg8.hpp"

Reg8::Reg8(MX3board * temp_board, unsigned char temp_addr) {
    board = temp_board;
    addr = temp_addr;
    tty = board->tty;
}


void Reg8::operator=(unsigned char data){
    board->board_d_write(addr, data);
}

Reg8::operator unsigned char(){
    return board->board_d_read(addr);
}

bool Reg8::operator[](int indice){
    return 1;
}
