/*****************************************
 * Darrel Daquigan
 * 915744913
 * darreldaquigan@sfsu.edu
 * Cygwin64 2.2.1
 *****************************************/

#include "map.h"

Map::Map()
{
  size = 0;
  items = NULL;
}

Map::Map( int newSize )
{
  size = newSize;
  items = new MapItem[ size * size ];

  for ( int i = 0; i < size * size; i++ )
  {
    items[i].setType( 'E' );
  }
}

Map::~Map()
{
  delete [] items;
  size = 0;
}

int Map::getSize()
{
  return size;
}

void Map::build( int y, int x, char type )
{
  int mapItemIndex = ( y * size ) + x;
  items[ mapItemIndex ].setType( type );
}

MapItem Map::getMapItem( int y, int x)
{
  int mapItemIndex = ( y * size ) + x;

  return items[ mapItemIndex ];
}

ifstream& operator >> ( ifstream& in, Map& map )
{
  delete [] map.items;

  in >> map.size;
  map.items = new MapItem[ map.size * map.size ];

  char type;

  for ( int i = 0; i < map.size * map.size; i++ )
  {
    in >> type;
    map.items[ i ].setType( type );
  }

  return in;
}

ofstream& operator << ( ofstream& out, const Map& map )
{
  out << map.size << '\n';

  for ( int i = 0; i < map.size * map.size; i++ )
  {
    out << map.items[ i ].getType() << ' ';
  }

  return out;
}

ostream& operator << ( ostream& out, const Map& map )
{
  char code;

  for ( int y = 0; y < map.size; y++ )
  {
    for ( int x = 0; x < map.size; x++)
    {
      code =  map.items[ y * map.size + x ].getType();
      out << code << ' ';
    }
    
    out << '\n';
  }

  return out;
}