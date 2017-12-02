#ifndef __OP_OVERLOADING_TEST_H__
#define __OP_OVERLOADING_TEST_H__

#include <iostream>
#include <fstream>

#include "map.h"
#include "map_item.h"

using namespace std;

class OperatorOverloadingTest {
  public:
    OperatorOverloadingTest();
    ~OperatorOverloadingTest();
    void run_tests();

    const int MAP_TEST_SIZE = 10;

  private:
    void print_header( string );
    void print_test( bool );

    void check_map_item_default_constructor();
    void check_map_item_constructor();
    void check_map_item_get_type();
    void check_map_item_set_type();
    void check_map_item_ostream_insertion_implemented();
    void check_map_item_ifstream_ofstream_implemented();

    void check_map_size();
    void check_map_default_building();
    void check_map_build();
    void check_map_coordinates_correct();
    void check_map_ostream_insertion_implemented();
    void print_expected_map_output();
    void check_map_ifstream_ofstream_implemented();
    Map * make_pretty_map( int );

    Map * map;
    char * codes;
};

#endif