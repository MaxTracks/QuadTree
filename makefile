CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -Wextra
LINK.o = $(CXX)

all:main

main: main.o generator.o

main.o: main.cpp quadtree.h quadtree.cpp

generator.o: generator.h generator.cpp

clean:
	rm -f *.o *~ main
