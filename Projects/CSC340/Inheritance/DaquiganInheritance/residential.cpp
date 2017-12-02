/*****************************************
 * Darrel Daquigan
 * 915744913
 * darreldaquigan@sfsu.edu
 * Cygwin64 2.2.1
 *****************************************/

#include "residential.h"

Residential::Residential()
{
  capacity = 1;
  taxRevenue = 0;
}

Residential::~Residential()
{

}

void Residential::tick()
{
  taxRevenue += capacity * 0.1;
}

double Residential::collectTaxes()
{
  double tax = taxRevenue;
  taxRevenue = 0;

  return tax;
}

