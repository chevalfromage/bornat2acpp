#include "Reg8.hpp"

Reg8::Reg8(MX3board& temp_board, unsigned char temp_addr) : board { temp_board} {
    //board = temp_board;
    addr_led = temp_addr;
}

void Reg8::operator=(unsigned char data){
    board.board_d_write(addr_led, data);
}

Reg8::operator unsigned char(){
    return board.board_d_read(MX3ADDR_SW);
}