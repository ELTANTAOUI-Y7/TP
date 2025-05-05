CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

EXECUTABLES = ex1 ex2 ex3

all: $(EXECUTABLES)

ex1: ex1.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

ex2: ex2.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

ex3: ex3.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(EXECUTABLES) *.o

.PHONY: all clean 