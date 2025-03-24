//register definitions

#include "mx3_board.hpp"
#include "Reg8.hpp"

int main(int argc, char *argv[]) {
    MX3board brd { argv[1] };
    //Reg8 myReg8 {brd, MX3ADDR_LED};

    Reg8 myReg8 = brd[MX3ADDR_SW];

    myReg8=0x2;

    unsigned char etat_switchs = myReg8;
    std::cout << (int)etat_switchs << std::endl;


    return 0;
}