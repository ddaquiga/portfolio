/*****************************************
 * Darrel Daquigan
 * 915744913
 * darreldaquigan@sfsu.edu
 * Cygwin64 2.2.1
 *****************************************/

#include "map_item.h"

MapItem::MapItem()
{
  type = 'E';
}

MapItem::MapItem( char newType )
{
  type = newType;
}

char MapItem::getType()
{
  return type;
}

void MapItem::setType( char newType )
{
  type = newType;
}

ifstream& operator >> ( ifstream& streamIn, MapItem& mapItem)
{
  streamIn >> mapItem.type;

  return streamIn;
}

ostream& operator << ( ostream& streamOut, const MapItem& mapItem )
{
  streamOut << mapItem.type;
  
  return streamOut;
}

