CXX = g++
CXXFLAGS = -Wall -g
SRCS = main.cpp
TARGET = main

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

fclean: clean
	rm -rf $(TARGET)
clean:
	rm -rf $(OBJS)

run: all
	./$(TARGET)

.PHONY: all clean
