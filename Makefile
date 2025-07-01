# Makefile for Odyssey Game (C++)

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -O2
TARGET = game
SOURCES = Entity.cpp Game.cpp Map.cpp GameDriver.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET) *.o *.exe

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run 