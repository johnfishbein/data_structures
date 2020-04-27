#Makefile -- jhf5my -- John Fishbein
CXX= clang++ -m64
CXXFLAGS= -Wall -g
AS= nasm
ASFLAGS= -f elf64 -g

OFILES= timer.o threexinput.o threexplusone.o

.SUFFIXES: .o .cpp
.SUFFIXES: .o .s

a.out:	$(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

clean:
	-rm -f *.o *~ a.out

threexinput.o: threexinput.cpp timer.h
timer.o: timer.cpp timer.h
