CXX = g++
CXXFLAGS = -Wall -Wfatal-errors -ggdb -pthread

TARGETS = main, ex3

.PHONY:	clean cleanall

all: $(TARGETS)

main: main.o utils.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

ex2: ex3.o utils.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f *.o

cleanall:	clean
	rm -f $(TARGETS) 
