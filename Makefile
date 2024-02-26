CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: llrec-test.cpp llrec.o
	$(CXX) $(CPPFLAGS) llrec-test.cpp llrec.o -o llrec-test

llrec: llrec.cpp llrec.h
	$(CXX) $(CPPFLAGS) -c llrec.cpp -o llrec.o

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 