all: main test_read_FEN test_write_FEN test_king test_rook test_bishop test_queen test_knight test_pawn test_movable test_attacked test_take

# Fichiers objets
board.o: board.cpp board.hpp types.hpp
	g++ -W -Wall -c board.cpp

view.o: view.cpp view.hpp types.hpp board.hpp
	g++ -W -Wall -c view.cpp

mask.o: mask.cpp mask.hpp types.hpp
	g++ -W -Wall -c mask.cpp

# Executable principal
main: main.cpp board.o view.o mask.o
	g++ -W -Wall main.cpp board.o view.o mask.o -o main

# Executable test lecture FEN
test_read_FEN: test_read_FEN.cpp board.o view.o
	g++ -W -Wall test_read_FEN.cpp board.o view.o -o test_read_FEN

# Executable test ecriture FEN
test_write_FEN: test_write_FEN.cpp board.o view.o
	g++ -W -Wall test_write_FEN.cpp board.o view.o -o test_write_FEN

# Tests des masques de deplacements
test_king: testKing.cpp board.o view.o mask.o
	g++ -W -Wall testKing.cpp board.o view.o mask.o -o test_king

test_rook: testRook.cpp board.o view.o mask.o
	g++ -W -Wall testRook.cpp board.o view.o mask.o -o test_rook

test_bishop: testBishop.cpp board.o view.o mask.o
	g++ -W -Wall testBishop.cpp board.o view.o mask.o -o test_bishop

test_queen: testQueen.cpp board.o view.o mask.o
	g++ -W -Wall testQueen.cpp board.o view.o mask.o -o test_queen

test_knight: testKnight.cpp board.o view.o mask.o
	g++ -W -Wall testKnight.cpp board.o view.o mask.o -o test_knight

test_pawn: testPawn.cpp board.o view.o mask.o
	g++ -W -Wall testPawn.cpp board.o view.o mask.o -o test_pawn

test_movable: testMovable.cpp board.o view.o mask.o
	g++ -W -Wall testMovable.cpp board.o view.o mask.o -o test_movable

test_attacked: testAttacked.cpp board.o view.o mask.o
	g++ -W -Wall testAttacked.cpp board.o view.o mask.o -o test_attacked

test_take: testTake.cpp board.o view.o mask.o
	g++ -W -Wall testTake.cpp board.o view.o mask.o -o test_take

clean:
	rm -f *.o main test_read_FEN test_write_FEN test_king test_rook test_bishop test_queen test_knight test_pawn test_movable test_attacked test_take