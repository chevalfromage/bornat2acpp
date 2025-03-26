//register definitions

#include "mx3_board.hpp"
#include "Reg8.hpp"
#include "Bit.hpp"

int main(int argc, char *argv[]) {
    MX3board brd { argv[1] };
    //Reg8 myReg8 {brd, MX3ADDR_LED};

    Reg8 myReg8SW = brd[MX3ADDR_SW];
    Reg8 myReg8LED = brd[MX3ADDR_LED];

    myReg8LED=0x0;

    Bit myBit {&myReg8LED, 1};
    myBit=1;

    bool LeBoule = myBit;
    std::cout << LeBoule << std::endl;
    

    unsigned char etat_switchs = myReg8SW;
    //std::cout << (int)etat_switchs << std::endl;
    brd << "trop bien";
    brd << "le language";
    brd << "C++";
    return 0;
}