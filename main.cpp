//register definitions

#include "mx3_board.hpp"
#include "Reg8.hpp"
#include "Bit.hpp"

int main(int argc, char *argv[]) {
    MX3board brd { argv[1] };
    //Reg8 myReg8 {brd, MX3ADDR_LED};

    Reg8 myReg8SW = brd[MX3ADDR_SW];
    Reg8 myReg8LED = brd[MX3ADDR_LED];

    Bit myBit {&myReg8LED};
    bool mesBoules[8]={1,1,1,1,0,1,1,1};

    //unsigned char monChar = 0x01;
    myBit=mesBoules;

    //myReg8LED=0x60;

    unsigned char etat_switchs = myReg8SW;
    std::cout << (int)etat_switchs << std::endl;
    brd << "trop bien";
    brd << "le language";
    brd << "C++";
    return 0;
}