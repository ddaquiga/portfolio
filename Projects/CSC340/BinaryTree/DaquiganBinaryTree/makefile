CC=g++ -std=c++11
CFLAGS=-c -g -Wall

all: driver

driver: main.o binary_tree_test.o
	$(CC) main.o binary_tree_test.o -g -o driver

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

binary_tree_test.o: binary_tree_test.cpp binary_tree_test.h
	$(CC) $(CFLAGS) binary_tree_test.cpp

clean:
	rm driver *.o