CXX= clang++ -std=c++11
CXXFLAGS= -g -Wall
ENCFILES= huffmanenc.o heap.o huffNode.o
DECFILES= huffmandec.o huffNode.o

.SUFFIXES: .o .cpp

main: enc dec

enc:	$(ENCFILES)
	$(CXX) $(CXXFLAGS) $(ENCFILES) -o encoder

dec:	$(DECFILES)
	$(CXX) $(CXXFLAGS) $(DECFILES) -o decoder


clean:
	rm -f *.o *~ encoder decoder



heap.o: heap.cpp heap.h huffNode.h
huffmandec.o: huffmandec.cpp huffNode.h
huffmanenc.o: huffmanenc.cpp heap.h huffNode.h
huffNode.o: huffNode.cpp huffNode.h
