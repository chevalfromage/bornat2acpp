//register definitions

#include "mx3_board.hpp"
#include "Reg8.hpp"
#include "Bit.hpp"

int main(int argc, char *argv[]) {
    MX3board brd { argv[1] };

    Reg8 myReg8SW = brd[MX3ADDR_SW];
    Reg8 myReg8LED = brd[MX3ADDR_LED];


//Tests sur la class Reg8

    unsigned char etat_switchs = myReg8SW;
    std::cout << "Etat des switch sur la board : " << (int)etat_switchs << std::endl;

    myReg8LED=0x2;

//Tests sur la class Bit

    std::cout << "Reg8LED avant changement d'un bit : " <<(int)myReg8LED << std::endl;
    Bit myBit {&myReg8LED, 1};

    bool LeBoule = myBit;
    std::cout << "Récupération de la valeur de myBit :"<< LeBoule << std::endl;

    myBit=1;
    std::cout << "Reg8LED après changement d'un bit : " << (int)myReg8LED << std::endl;
    
    bool unBitDeLED = myReg8LED[0];
    std::cout << "On regarde un bit dans un Reg8 : " << (int)unBitDeLED << std::endl;
    

//Test sur l'écran LCD

    brd << "trop bien";
    brd << "le language";
    brd << "C++";
    return 0;
}