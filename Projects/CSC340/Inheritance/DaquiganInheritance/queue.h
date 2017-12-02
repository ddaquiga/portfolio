/*****************************************
 * Darrel Daquigan
 * 915744913
 * darreldaquigan@sfsu.edu
 * Cygwin64 2.2.1
 *****************************************/

#ifndef QUEUE
#define QUEUE

#include "Node.h"

#include <stddef.h>
#include <iostream>

 using namespace std;

class Queue
{
public:
  Queue();
  ~Queue();
  void enqueue( int );
  int dequeue();
  int front();
  bool isEmpty();
  int size();

private:
  Node * beginning;
  Node * end;
  int count;

};

#endif

