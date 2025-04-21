CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRCS = main.cpp Resource.cpp Container.cpp Pod.cpp Server.cpp KubernetesCluster.cpp Cloud_Util.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = cloud_simulator

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) 