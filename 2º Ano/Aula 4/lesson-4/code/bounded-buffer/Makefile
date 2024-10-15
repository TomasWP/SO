CXX = g++
CXXFLAGS = -Wall -ggdb -pthread

TARGETS = bb-unsafe bb-safe training1

OBJS = thread.o utils.o

.PHONY:	all clean cleanall

all: $(TARGETS)

bb-unsafe: main.o fifo-unsafe.o $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

bb-safe: main.o fifo-mon-safe.o $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

training1: training1.o $(OBJS) $(HEADERS)
	$(CXX) -o $@ training1.o $(OBJS) $(CXXFLAGS)

training2: training2.o $(OBJS) $(HEADERS)
	$(CXX) -o $@ training2.o $(OBJS) $(CXXFLAGS)

*.o:	*.h

clean:
	rm -f *.o

cleanall:	clean
	rm -f $(TARGETS) 
