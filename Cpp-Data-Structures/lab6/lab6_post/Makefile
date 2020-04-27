#jhf5my -- John Fishbein -- Monday 4 March 2019
CXX=clang++
CXXFLAGS=-Wall -O2 -std=c++11
OFILES= hashTable.o wordPuzzle.o timer.o

.SUFFIXES: .o .cpp

a.out: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)
clean:
	-rm -f *.o *~ a.out

hashTable.o: hashTable.cpp hashTable.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
timer.o: timer.cpp timer.h

