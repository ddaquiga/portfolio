#ifndef __INHERITANCE_TEST_H__
#define __INHERITANCE_TEST_H__

#include <string>

#include "map_item.h"
#include "no_op_item.h"
#include "residential.h"
#include "factory.h"

using namespace std;

class InheritanceTest {
  public:
    InheritanceTest();
    ~InheritanceTest();
    void run_tests();

  private:
    void print_header( string );
    void print_test( bool );

    void check_no_op_item();

    void check_factory();
    void check_factory_can_produce();
    void check_factory_tick();
    void check_factory_tick_empty();
    void check_factory_get_produced_item_empty();

    void check_residential();
    void check_residential_collect_taxes_empty();
    void check_residential_tick();

    bool doubleEquals(double, double);
    double abs( double );
};

#endif