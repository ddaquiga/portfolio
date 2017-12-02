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

driver: main.o op_overloading_test.o map.o map_item.o
	$(CC) main.o op_overloading_test.o map.o map_item.o -g -o driver

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

op_overloading_test.o: op_overloading_test.cpp op_overloading_test.h
	$(CC) $(CFLAGS) op_overloading_test.cpp

map.o: map.cpp map.h
	$(CC) $(CFLAGS) map.cpp

map_item.o: map_item.cpp map_item.h
	$(CC) $(CFLAGS) map_item.cpp

clean:
	rm -f *.o driver blarg avada kedavra