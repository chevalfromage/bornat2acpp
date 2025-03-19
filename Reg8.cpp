#include "Reg8.hpp"

Reg8::Reg8(MX3board& temp_board, unsigned char temp_addr) : board { temp_board} {
    //board = temp_board;
    addr = temp_addr;
}

void Reg8::operator=(unsigned char data){
    
    unsigned char gen[3];
    gen[0] = MX3CMD_WR1;
    gen[1] = addr;
    gen[2] = data;

    std::cout << "operator lance     " << tty <<"     " <<(int)gen[0] <<"     "<< (int)gen[1] <<"     "<< (int)gen[2] <<std::endl;

    // actually send command
    write(tty, gen, 3);
}