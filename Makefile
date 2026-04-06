all: main test_read_FEN test_write_FEN

# Fichiers objets
board.o: board.cpp board.hpp types.hpp
	g++ -W -Wall -c board.cpp

view.o: view.cpp view.hpp types.hpp board.hpp
	g++ -W -Wall -c view.cpp

mask.o: mask.cpp mask.hpp types.hpp
	g++ -W -Wall -c mask.cpp

# Exécutable principal
main: main.cpp board.o view.o mask.o
	g++ -W -Wall main.cpp board.o view.o mask.o -o main

# Exécutable test lecture FEN
test_read_FEN: test_read_FEN.cpp board.o view.o
	g++ -W -Wall test_read_FEN.cpp board.o view.o -o test_read_FEN

# Exécutable test écriture FEN
test_write_FEN: test_write_FEN.cpp board.o view.o
	g++ -W -Wall test_write_FEN.cpp board.o view.o -o test_write_FEN
	# Tests des masques de déplacements 
test_king: test_king.cpp board.o view.o mask.o
	g++ -W -Wall test_king.cpp board.o view.o mask.o -o test_king
 
test_rook: test_rook.cpp board.o view.o mask.o
	g++ -W -Wall test_rook.cpp board.o view.o mask.o -o test_rook
 
test_bishop: test_bishop.cpp board.o view.o mask.o
	g++ -W -Wall test_bishop.cpp board.o view.o mask.o -o test_bishop
 
test_queen: test_queen.cpp board.o view.o mask.o
	g++ -W -Wall test_queen.cpp board.o view.o mask.o -o test_queen
 
test_knight: test_knight.cpp board.o view.o mask.o
	g++ -W -Wall test_knight.cpp board.o view.o mask.o -o test_knight
 
test_pawn: test_pawn.cpp board.o view.o mask.o
	g++ -W -Wall test_pawn.cpp board.o view.o mask.o -o test_pawn
 
test_movable: test_movable.cpp board.o view.o mask.o
	g++ -W -Wall test_movable.cpp board.o view.o mask.o -o test_movable
 
test_attacked: test_attacked.cpp board.o view.o mask.o
	g++ -W -Wall test_attacked.cpp board.o view.o mask.o -o test_attacked
 
test_take: test_take.cpp board.o view.o mask.o
	g++ -W -Wall test_take.cpp board.o view.o mask.o -o test_take
 

clean:
	rm -f *.o main test_read_FEN test_write_FEN test_king test_rook test_bishop test_queen test_knight test_pawn test_movable test_attacked test_take
	
	
//Elle sert à supprimer tous les fichiers générés par la compilation pour repartir de zéro.