#include "Reg8.hpp"

Reg8::Reg8(MX3board * temp_board, unsigned char temp_addr) {
    board = temp_board;
    addr_led = temp_addr;
    tty = board->tty;
}


void Reg8::operator=(unsigned char data){
    board->board_d_write(MX3ADDR_LED, data);
}

Reg8::operator unsigned char(){
    return board->board_d_read(MX3ADDR_SW);
}