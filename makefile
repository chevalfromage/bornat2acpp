main : mx3_board.o main.o Reg8.o Bit.o
	g++ -o main mx3_board.o main.o Reg8.o Bit.o

mx3_board.o : mx3_board.cpp mx3_board.hpp
	g++ -c mx3_board.cpp

reg8.o : Reg8.cpp Reg8.hpp
	g++ -c Reg8.cpp

Bit.o : Bit.cpp Bit.hpp
	g++ -c Bit.cpp

main.o : main.cpp mx3_board.hpp Reg8.o Bit.o
	g++ -c main.cpp

clean :
	rm -f *.o