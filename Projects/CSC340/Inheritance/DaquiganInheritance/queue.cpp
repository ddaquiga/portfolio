/*****************************************
 * Darrel Daquigan
 * 915744913
 * darreldaquigan@sfsu.edu
 * Cygwin64 2.2.1
 *****************************************/

#include "queue.h"

Queue::Queue()
{
  beginning = NULL;
  end = NULL;
  count = 0;
}

Queue::~Queue()
{
  Node * current = beginning;

  while ( current != NULL )
  {
    Node * next = current->next;
    delete current;
    current = next;
  }

  delete current;

  count = 0;
  beginning = NULL;
  end = NULL;

}

void Queue::enqueue( int newValue )
{
  if( beginning == NULL )
  {
    beginning = new Node( newValue );
    end = beginning;
  }

  else
  {
    end->next = new Node( newValue );
    end = end->next;
  }

  count++;
}

int Queue::dequeue()
{
  if ( isEmpty() )
  {
    return -1;
  } 

  else
  {
    int frontValue = beginning->value;

    Node *trashCopy = beginning;
    beginning = beginning->next;
    delete trashCopy;

    count--;

    return frontValue;
  }
}

int Queue::front()
{
  return beginning->value;
}

bool Queue::isEmpty()
{
  return ( beginning == NULL );
}

int Queue::size()
{
  return count;
}

