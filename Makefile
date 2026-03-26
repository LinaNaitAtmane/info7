CXX = g++
CXXFLAGS = -W -Wall

all: main test_read_FEN test_write_FEN

# Fichiers objets
board.o: board.cpp board.hpp types.hpp
	$(CXX) $(CXXFLAGS) -c board.cpp

view.o: view.cpp view.hpp types.hpp board.hpp
	$(CXX) $(CXXFLAGS) -c view.cpp

# Exécutable principal
main: main.cpp board.o view.o
	$(CXX) $(CXXFLAGS) main.cpp board.o view.o -o main

# Exécutable test lecture FEN
test_read_FEN: test_read_FEN.cpp board.o view.o
	$(CXX) $(CXXFLAGS) test_read_FEN.cpp board.o view.o -o test_read_FEN

# Exécutable test écriture FEN
test_write_FEN: test_write_FEN.cpp board.o view.o
	$(CXX) $(CXXFLAGS) test_write_FEN.cpp board.o view.o -o test_write_FEN

clean:
	rm -f *.o main test_read_FEN test_write_FEN