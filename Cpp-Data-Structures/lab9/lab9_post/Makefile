CXX= clang
CXXFLAGS= -g -Wall

.SUFFIXES: .o .c

a.out: linkedlist.c
	$(CXX) $(CXXFLAGS) linkedlist.c

clean:
	-rm -f *.o *~ a.out

linkedlist.o: linkedlist.c
