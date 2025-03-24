//register definitions

#include "mx3_board.hpp"
#include "Reg8.hpp"

int main(int argc, char *argv[]) {
    MX3board brd { argv[1] };
    //Reg8 myReg8 {brd, MX3ADDR_LED};

    Reg8 myReg8SW = brd[MX3ADDR_SW];
    Reg8 myReg8LED = brd[MX3ADDR_LED];

    myReg8LED=0x60;

    unsigned char etat_switchs = myReg8SW;
    std::cout << (int)etat_switchs << std::endl;

    brd << "zizi";
    return 0;
}