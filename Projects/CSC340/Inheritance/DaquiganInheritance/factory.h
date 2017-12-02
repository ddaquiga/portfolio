/*****************************************
 * Darrel Daquigan
 * 915744913
 * darreldaquigan@sfsu.edu
 * Cygwin64 2.2.1
 *****************************************/

#ifndef FACTORY
#define FACTORY

#include "queue.h"
#include "map_item.h"

class Factory : public MapItem
{
private:
	int countSinceLastProduced;
	Queue * production;
	Queue * produced;

public:
	Factory();
	virtual ~Factory();
	void tick();
	void produceItem( int );
	int getProducedItem();
	int productionCount();
	int producedCount();
};

#endif