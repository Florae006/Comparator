CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -ggdb 

SRC := main.cpp

TARGET := main

build-only: $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $(TARGET)

main: build-only
	./$(TARGET)

clean:
	@rm -rf $(TARGET)

hack: hack.cpp
	$(CXX) $(CXXFLAGS) $< -o hack

cmp: comparator.cpp
	$(CXX) $(CXXFLAGS) $< -o comparator

judgecmp: ./judge/main.cpp
	$(CXX) $(CXXFLAGS) $< -o ./judge/main


.PHONY:
	clean build-only
