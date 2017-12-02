/*****************************************
 * Darrel Daquigan
 * 915744913
 * darreldaquigan@sfsu.edu
 * Cygwin64 2.2.1
 *****************************************/

#ifndef NODE
#define NODE

#include <stddef.h>

class Node
{
public:
  Node( int );
  Node * next;
  int value;
};

#endif