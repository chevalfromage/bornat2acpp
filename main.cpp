//register definitions
#include "mx3_board.hpp"
#include "Reg8.hpp"

int main(int argc, char *argv[]) {
    MX3board brd { argv[1] };
    //MX3board* p = &brd;
    //std::cout << &brd->tty << std::endl;
    //brd.board_d_write(MX3ADDR_LED, 0x60);
    Reg8 myReg8 {brd, MX3ADDR_LED};
    myReg8=0x60;
    //std::cout << "Valeur des switchs : " << (int)brd[MX3ADDR_SW] << std::endl;

    return 0;

    // // check that we received the filename of the tty connection
    // if (argc<2) {
    //     printf("No device name provided\n");
    //     return -1;
    // }
    // MX3board myBoard;
    // // opens the connection
    // int tty = myBoard.board_open(argv[1]);
    // if (tty<0) {
    //     return -1;
    // }

    // // set even numbered LEDs, clear odd numbered LEDs
    // myBoard.board_d_write(tty, MX3ADDR_LED, 0x80);

    // // retreive switches values (and display it)
    // myBoard.last_error = 0;
    // unsigned char sw = myBoard.board_d_read(tty, MX3ADDR_SW);
    // if (myBoard.last_error == 0) {
    //     printf("Switches value : 0x%X\n", sw);
    // }

    // // close board
    // myBoard.board_close(tty);
    // return 0;
}