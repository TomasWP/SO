CXX = g++
CXXFLAGS = -Wall -Wfatal-errors -ggdb -pthread

TARGETS = main

.PHONY: clean cleanall

all: $(TARGETS)

main: main.cpp process.cpp utils.cpp
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	del /Q *.o

cleanall: clean
	del /Q $(TARGETS).exe


