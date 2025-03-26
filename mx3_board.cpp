

#include "mx3_board.hpp"


MX3board::MX3board(const char* temp_port){
    port = (char*)temp_port;
    this->board_open();
}

void MX3board::board_close(int tty) {
    std::cout << "Closing board connection\n" << std::endl;
    close(tty);
}

int MX3board::board_open(){
    // opens a TTY (UART) connection to the board
    // also sets communication parameters
    // returns a file description number (if positive) or an error code
    // if negative. Error codes :
    //     -1 : unable to open the tty descriptor
    //     -2 : unable to clean data received before the function call
    //     -3 : unable to clean data sent by previous program and not sent yet
    //     -4 : error reported while setting necessary parameters

    // opening the file entry
    tty = open(port, O_RDWR);
    if (tty == 0) {
        std::cout << "Unable to connect to board\n" << std::endl;
        return -1;
    }
    std::cout << "Board connection opened\n" << std::endl;

    // preparing the parameter set
    struct termios newtermios;
    newtermios.c_cflag= CBAUD | CS8 | CLOCAL | CREAD;   // 8bits
    newtermios.c_iflag=IGNPAR;                          // no parity
    newtermios.c_oflag=0;                               // -- no other option --
    newtermios.c_lflag=0;                               // -- no other option --
    newtermios.c_cc[VMIN]=1;                            // 100 ms timeout
    newtermios.c_cc[VTIME]=0;                           // no delay for flush
    cfsetospeed(&newtermios,B115200);
    cfsetispeed(&newtermios,B115200);

    // clean input buffer
    if (tcflush(tty,TCIFLUSH)==-1) {
        std::cout << "Unable to flush board connection input\n" << std::endl;
        board_close(tty);
        return -2;
    }
    // clean output buffer
    if (tcflush(tty,TCOFLUSH)==-1){
        std::cout << "Unable to flush board connection output\n" << std::endl;
        board_close(tty);
        return -3;
    }
    // actually set parameters
    if (tcsetattr(tty,TCSANOW,&newtermios)==-1){
        std::cout << "Unable to set connection parameters\n" << std::endl;
        board_close(tty);
        return -4;
    }

    // job's done !
    std::cout << "Board connection ready\n" << std::endl;
    return tty;
}

void MX3board::board_d_write( unsigned char addr, unsigned char data) {
    // write value 'data' at address 'addr'

    // prepare command
    unsigned char gen[3];
    gen[0] = MX3CMD_WR1;
    gen[1] = addr;
    gen[2] = data;
    std::cout << "operator lance     " << tty <<"     " <<(int)gen[0] <<"     "<< (int)gen[1] <<"     "<< (int)gen[2] <<std::endl;

    // actually send command
    write(tty, gen, 3);
}

unsigned char MX3board::board_d_read( unsigned char addr) {
    // read (and return) value stored at address 'addr'
    // if data is not received, simply returns 0, and set the global variable
    // 'last_error' to -1. to catch this error, user must clear 'last_error'
    // prior calling this function, then check 'last_error' value

    // this behavior is intentionnally not comfortable, you may provide
    // your own C++ specific behavior (or not)

    // prepare command
    unsigned char gen[2];
    gen[0] = MX3CMD_RD1;
    gen[1] = addr;

    // actually send command
    write(tty, gen, 2);
    // retreive data from board (1 byte)
    if (!read(tty, gen, 1)) {
        // read returned 0 (no data received)
        std::cout << "No answer from board\n" << std::endl;
        last_error = -1;
        return 0;
    }
    
    return gen[0];
}

Reg8 MX3board::operator[](unsigned char addr){
    //MX3board instance = *this;
    Reg8 temp {this, addr};
    return temp;
}


void MX3board::operator<<(const std::string& message) {
    int addr = MX3ADDR_LCD_START;

    

    const std::string& efface = "                                ";
    for (size_t i = 0; i < efface.size(); ++i) {
        board_d_write(addr + i, efface[i]);
    }  
    for (size_t i = 0; i < lcd_precedent.size(); ++i) {
        board_d_write(addr + i, lcd_precedent[i]);
    } 
    for (size_t i = 0; i < message.size(); ++i) {
        board_d_write(addr + i+16, message[i]);
    }
    
    lcd_precedent = message;
    //std::cout << "message: " << message << std::endl;
}


