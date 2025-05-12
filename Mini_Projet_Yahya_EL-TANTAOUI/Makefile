# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Executable name
TARGET = main

# Source files
SRCS = main2.cpp \
       Resource.cpp \
       Container.cpp \
       Pod.cpp \
       Server.cpp \
       KubernetesCluster.cpp \
       Cloud_Util.cpp \
       MetricLogger.cpp
	   
# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean compiled files
clean:
	del -f $(TARGET) *.o
	del -f $(TARGET) *.exe

# Run the program
run: all
	./$(TARGET)
