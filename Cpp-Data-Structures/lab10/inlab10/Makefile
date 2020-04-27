CXX= clang++ -std=c++11
CXXFLAGS= -g -Wall
OFILES= huffmandec.o huffNode.o

.SUFFIXES: .o .cpp


a.out:	$(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

clean:
	rm -f *.o *~ a.out


huffmandec.o: huffmandec.cpp huffNode.h
huffNode.o: huffNode.cpp huffNode.h
