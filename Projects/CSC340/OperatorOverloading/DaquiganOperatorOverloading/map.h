/*****************************************
 * Darrel Daquigan
 * 915744913
 * darreldaquigan@sfsu.edu
 * Cygwin64 2.2.1
 *****************************************/

#ifndef MAP
#define MAP

#include "map_item.h"

#include <fstream>
#include <iostream>

using namespace std;

class Map
{
public:
  Map();
  explicit Map( int );
  ~Map();
  int getSize();
  void build( int, int, char );
  MapItem getMapItem( int, int );
  friend ifstream& operator >> ( ifstream&, Map& );
  friend ofstream& operator << ( ofstream&, const Map& );
  friend ostream& operator << ( ostream&,  const Map& );

private:
  int size;
  MapItem * items;

};

#endif