/*****************************************
 * Darrel Daquigan
 * 915744913
 * darreldaquigan@sfsu.edu
 * Cygwin64 2.2.1
 *****************************************/

#ifndef MAP_ITEM
#define MAP_ITEM

#include <fstream>
#include <iostream>

using namespace std;

class MapItem
{
public:
  MapItem();
  MapItem( char );
  char getType();
  void setType( char );
  friend ifstream& operator >> ( ifstream&, MapItem& );
  friend ostream& operator << ( ostream&, const MapItem& );

private:
  char type;
};

#endif