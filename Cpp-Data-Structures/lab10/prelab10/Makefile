CXX= clang++ -std=c++11
CXXFLAGS= -g -Wall
OFILES= huffmanenc.o heap.o huffNode.o

.SUFFIXES: .o .cpp


a.out:	$(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

clean:
	rm -f *.o *~ a.out


heap.o: heap.cpp heap.h huffNode.h
huffmanenc.o: huffmanenc.cpp heap.h huffNode.h
huffNode.o: huffNode.cpp huffNode.h
