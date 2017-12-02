# Makefile entries are arranged as sets of targets to build, dependencies
# required to build that target, and the system command to build the target:
#
# target: dependencies
# [tab] system_command
#
# We can also use variables in our makefile, to make it easier to change
# compilers, or compilation flags.  The variable values are substituted
# wherever you see the $(VARIABLE) in the makefile
CC=g++ -std=c++11
CFLAGS=-c -g -Wall

all: driver

driver: main.o graph_test.o graph.o vertex.o
	$(CC) main.o graph_test.o graph.o vertex.o -g -o driver

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

graph_test.o: graph_test.cpp graph_test.h
	$(CC) $(CFLAGS) graph_test.cpp

graph.o: graph.cpp graph.h
	$(CC) $(CFLAGS) graph.cpp

vertex.o: vertex.cpp vertex.h
	$(CC) $(CFLAGS) vertex.cpp

clean:
	rm -f *.o driver