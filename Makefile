
all: main test_read_FEN test_write_FEN

# Fichiers objets
board.o: board.cpp board.hpp types.hpp
	g++ -W -Wall -c board.cpp

view.o: view.cpp view.hpp types.hpp board.hpp
	g++ -W -Wall -c view.cpp

# Exécutable principal
main: main.cpp board.o view.o
	g++ -W -Wall main.cpp board.o view.o -o main

# Exécutable test lecture FEN
test_read_FEN: test_read_FEN.cpp board.o view.o
	g++ -W -Wall test_read_FEN.cpp board.o view.o -o test_read_FEN

# Exécutable test écriture FEN
test_write_FEN: test_write_FEN.cpp board.o view.o
	g++ -W -Wall test_write_FEN.cpp board.o view.o -o test_write_FEN


# Ajouter la règle pour mask.o
mask.o: mask.cpp mask.hpp types.hpp
 g++ -W -Wall  -c mask.cpp

# Modifier les règles qui en ont besoin
main: main.cpp board.o view.o mask.o
g++ -W -Wall  main.cpp board.o view.o mask.o -o main


clean:
	rm -f *.o main test_read_FEN test_write_FEN