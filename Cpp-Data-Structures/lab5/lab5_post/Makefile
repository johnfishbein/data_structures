#jhf5my -- John Fishbein -- Tuesday 26 February 2019 -- Makefile
CXX=clang++
CXXFLAGS=-Wall -O2 -std=c++11
DEBUG=-g
OFILES= AVLNode.o AVLTree.o AVLPathTest.o

.SUFFIXES: .o .cpp

a.out: $(OFILES)
	$(CXX) $(CXXFLAGS) $(DEBUG) $(OFILES)

clean:
	-rm -f *.o *~ a.out

AVLNode.o: AVLNode.cpp AVLNode.h
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
AVLTree.o: AVLTree.cpp AVLTree.h AVLNode.h
