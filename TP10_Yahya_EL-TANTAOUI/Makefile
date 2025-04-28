CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

EXECS = exo1 exo2 exo3 exo4

all: $(EXECS)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(EXECS) *.o

.PHONY: all clean 