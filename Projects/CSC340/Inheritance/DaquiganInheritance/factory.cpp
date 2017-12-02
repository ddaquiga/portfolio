/*****************************************
 * Darrel Daquigan
 * 915744913
 * darreldaquigan@sfsu.edu
 * Cygwin64 2.2.1
 *****************************************/

#include "factory.h"

Factory::Factory()
{
  countSinceLastProduced = 0;
  production = new Queue();
  produced = new Queue();
}

Factory::~Factory()
{
  delete production;
  delete produced;
}

void Factory::tick()
{ 
  if ( production->isEmpty() ){
    countSinceLastProduced = 0;
  }
  
  else{
    while ( countSinceLastProduced != production->size() ){
      countSinceLastProduced++;
    }
    
    produced->enqueue( production->dequeue() );
    countSinceLastProduced--;
  }
}

void Factory::produceItem( int item )
{
  production->enqueue( item );
}

int Factory::getProducedItem()
{
  if ( produced->isEmpty() ){
    return -1;
  }
  
  return produced->dequeue();
}

int Factory::productionCount()
{
  return production->size();
}

int Factory::producedCount()
{
  return produced->size();
}