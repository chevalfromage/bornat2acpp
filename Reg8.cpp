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

// void Reg8::lcd(const std::string& message){
//     for(int i=0; i<=message.size(); i++){
//         board->board_d_write(addr+i, message[i]);
//     }
// }
