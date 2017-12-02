#include "op_overloading_test.h"

OperatorOverloadingTest::OperatorOverloadingTest() {
  map = new Map( MAP_TEST_SIZE );
  codes = new char[ MAP_TEST_SIZE * MAP_TEST_SIZE ];

  for( int i = 0; i < MAP_TEST_SIZE * MAP_TEST_SIZE; i++ ) {
    codes[ i ] = 'E';
  }
}

OperatorOverloadingTest::~OperatorOverloadingTest() {
  delete map;
  delete codes;
}

void OperatorOverloadingTest::run_tests() {
  check_map_item_default_constructor();
  check_map_item_constructor();
  check_map_item_get_type();
  check_map_item_set_type();
  check_map_item_ostream_insertion_implemented();
  check_map_item_ifstream_ofstream_implemented();

  check_map_size();
  check_map_default_building();
  check_map_build();
  check_map_coordinates_correct();
  check_map_ostream_insertion_implemented();
  check_map_ifstream_ofstream_implemented();
}

void OperatorOverloadingTest::check_map_item_default_constructor() {
  print_header( "map_item default constructor initializes to E" );

  MapItem item;

  print_test( item.getType() == 'E' );
}

void OperatorOverloadingTest::check_map_item_constructor() {
  print_header( "map_item constructor accepts char" );

  MapItem item( 'O' );

  print_test( item.getType() == 'O' );
}

void OperatorOverloadingTest::check_map_item_get_type() {
  print_header( "map_item sets type correctly" );

  MapItem item;
  item.setType( 'Z' );

  print_test( item.getType() == 'Z' );
}

void OperatorOverloadingTest::check_map_item_set_type() {
  print_header( "map_item gets type correctly" );

  MapItem item( 'Z' );

  print_test( item.getType() == 'Z' );
}

void OperatorOverloadingTest::check_map_item_ostream_insertion_implemented() {
  print_header( "map_item implements ostream << (visual comparison required)" );

  MapItem item( 'K' );

  cout << "EXPECTED:" << endl << "K" << endl;

  cout << endl << "IMPLEMENTED:" << endl;
  cout << item << endl;
}

void OperatorOverloadingTest::check_map_item_ifstream_ofstream_implemented() {
  print_header( "map_item implements ifstream/ofstream" );

  MapItem item('X');

  // Create and write map item with type X to output file
  ofstream outputFile;
  outputFile.open( "avada" );

  outputFile << item;
  outputFile.close();

  // Read the file we just wrote to into a new map item, and verify type
  ifstream inFile;
  inFile.open( "avada" );

  MapItem next_item;
  inFile >> next_item;
  inFile.close();

  print_test( next_item.getType() == 'X' );
}

void OperatorOverloadingTest::check_map_size() {
  print_header( "map size is correct" );
  print_test( map->getSize() == MAP_TEST_SIZE );
}

void OperatorOverloadingTest::check_map_default_building() {
  print_header( "map default buidling is 'E'");
  print_test( map->getMapItem( 0, 0 ).getType() == 'E' );
}

void OperatorOverloadingTest::check_map_build() {
  print_header( "map builds correctly" );

  map->build( 0, 1, 'O' );
  codes[ 1 ] = 'O';

  print_test( map->getMapItem( 0, 1 ).getType() == 'O' );
}

void OperatorOverloadingTest::check_map_coordinates_correct() {
  print_header( "map builds correctly (inverted coordinates)" );
  print_test( map->getMapItem( 1, 0 ).getType() == 'E' );
}

void OperatorOverloadingTest::check_map_ostream_insertion_implemented() {
  print_header( "map implements ostream << (visual comparison required)" );

  cout << "EXPECTED:" << endl;
  print_expected_map_output();

  cout << "IMPLEMENTED:" << endl;
  cout << *(map) << endl;
}

void OperatorOverloadingTest::print_expected_map_output() {
  for( int i = 0; i < MAP_TEST_SIZE * MAP_TEST_SIZE; i ++ ) {
    cout << codes[i] << " ";

    if( i > 0 && (i + 1) % MAP_TEST_SIZE == 0 ) {
      cout << endl;
    }
  }

  cout << endl;
}

void OperatorOverloadingTest::check_map_ifstream_ofstream_implemented() {
  print_header( "map implements ifstream/ofstream" );

  int test_size = MAP_TEST_SIZE / 2;
  Map * pretty_map = make_pretty_map( test_size );

  // Create file from map
  ofstream outputFile;
  outputFile.open( "kedavra");

  outputFile << *(pretty_map);
  outputFile.close();

  // Read it back in
  ifstream inFile;
  inFile.open( "kedavra" );

  Map next_map;
  inFile >> next_map;
  inFile.close();

  // Check a few things in the new next_map:
  bool result = true;

  result = result && ( next_map.getSize() == test_size );

  for( int i = 0; i < test_size; i++ ) {
    for( int j = 0; j < test_size; j++ ) {
      char pretty_type = pretty_map->getMapItem( i, j ).getType();
      char new_type = next_map.getMapItem( i, j ).getType();

      result = result && pretty_type == new_type;
    }
  }

  print_test( result );

  delete pretty_map;
}

Map * OperatorOverloadingTest::make_pretty_map( int test_size ) {
  Map * temp_map = new Map( test_size );

  for( int i = 0; i < test_size; i++ ) {
    temp_map->build( i, i, '\\' );
    temp_map->build( test_size - (i + 1), i, '/' );
    temp_map->build( test_size / 2, i, '-' );
    temp_map->build( i, test_size / 2, '|' );
  }

  return temp_map;
}

void OperatorOverloadingTest::print_header( string message ) {
  cout << "--- Testing " << message << " ---" << endl;
}

void OperatorOverloadingTest::print_test( bool result ) {
  if( result ) {
    cout << "PASS";
  } else {
    cout << "FAIL";
  }

  cout << endl;
}