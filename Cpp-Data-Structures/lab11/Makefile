CXX =clang++ -std=c++11
CXXFLAGS =-Wall -g
OFILES = topological.cpp

.SUFFIXES: .o .cpp

main:	$(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

	doxygen

clean:
	-rm -f *.o *~ a.out
