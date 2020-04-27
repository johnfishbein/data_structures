#jhf5my -- John Fishbein -- Monday 25 February 2019 Makefile
CXX=clang++
CXXFLAGS=-Wall -O2 -std=c++11 
DEBUG=-g
OFILES = BinaryNode.o BinarySearchTree.o BSTPathTest.o

.SUFFIXES: .o .cpp

a.out: $(OFILES)
	$(CXX) $(CXXFLAGS) $(DEBUG) $(OFILES)

clean:
	-rm -f *.o *~ a.out

BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h BinaryNode.h
BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
