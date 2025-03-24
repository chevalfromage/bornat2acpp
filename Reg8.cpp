#include "Reg8.hpp"

Reg8::Reg8(MX3board& temp_board, unsigned char temp_addr) : board { temp_board} {
    //board = temp_board;
    addr_led = temp_addr;
}

void Reg8::operator=(unsigned char data){
    
    unsigned char gen[3];
    gen[0] = MX3CMD_WR1;
    gen[1] = addr_led;
    gen[2] = data;

    std::cout << "operator lance     " << tty <<"     " <<(int)gen[0] <<"     "<< (int)gen[1] <<"     "<< (int)gen[2] <<std::endl;

    // actually send command
    write(tty, gen, 3);
}

Reg8::operator unsigned char(){
    return board.board_d_read(MX3ADDR_SW);
}