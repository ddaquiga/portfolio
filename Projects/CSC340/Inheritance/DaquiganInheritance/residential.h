/*****************************************
 * Darrel Daquigan
 * 915744913
 * darreldaquigan@sfsu.edu
 * Cygwin64 2.2.1
 *****************************************/

#ifndef RESIDENTIAL
#define RESIDENTIAL

#include "map_item.h"
#include <iostream>

class Residential : public MapItem
{
private:
  int capacity;
  double taxRevenue;

public:
  Residential();
  virtual ~Residential();
  void tick();
  double collectTaxes();
};

#endif