/*****************************************
 * Darrel Daquigan
 * 915744913
 * darreldaquigan@sfsu.edu
 * Cygwin64 2.2.1
 *****************************************/

#ifndef MAP_ITEM
#define MAP_ITEM

using namespace std;

class MapItem
{
public:
  MapItem();
  virtual ~MapItem();
  void virtual tick();
};

#endif