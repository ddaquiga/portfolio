#include "inheritance_test.h"

InheritanceTest::InheritanceTest() {

}

InheritanceTest::~InheritanceTest() {

}

void InheritanceTest::run_tests() {
  check_no_op_item();

  check_factory();
  check_factory_can_produce();
  check_factory_tick();
  check_factory_tick_empty();
  check_factory_get_produced_item_empty();

  check_residential();
  check_residential_collect_taxes_empty();
  check_residential_tick();
}

void InheritanceTest::check_no_op_item() {
  print_header( "Checking if NoOpItem is instantiable" );

  // This will fail if the NoOpItem is not implemented correctly
  MapItem * item = new NoOpItem();
  delete item;

  print_test( true );
}

void InheritanceTest::check_factory() {
  print_header( "Checking if Factory is instantiable" );

  // This will fail if the Factory is not implemented correctly
  MapItem * item = new Factory();
  delete item;

  print_test( true );
}

void InheritanceTest::check_factory_can_produce() {
  print_header( "Checking Factory::produceItem() and Factory::productionCount()" );

  Factory factory;
  factory.produceItem( 1 );

  print_test( factory.productionCount() == 1 );
}

void InheritanceTest::check_factory_tick() {
  print_header( "Checking Factory::tick(), Factory::producedCount(), and Factory::getProducedItem()" );

  Factory factory;
  factory.produceItem( 1 );
  factory.tick();

  print_test(
    factory.productionCount() == 0 &&
    factory.producedCount() == 1 &&
    factory.getProducedItem() == 1
  );
}

void InheritanceTest::check_factory_tick_empty() {
  print_header( "Checking Factory::tick() for empty production queue" );

  Factory factory;
  bool defaultsToEmpty = factory.productionCount() == 0 && factory.producedCount() == 0;
  factory.tick();

  print_test( defaultsToEmpty && factory.productionCount() == 0 && factory.producedCount() == 0 );
}

void InheritanceTest::check_factory_get_produced_item_empty() {
  print_header( "Checking Factory::getProducedItem() returns -1 when empty" );

  Factory factory;

  print_test( factory.getProducedItem() == -1 );
}

void InheritanceTest::check_residential() {
  print_header( "Checking if Residential is instantiable" );

  // This will fail if the Residential is not implemented correctly
  MapItem * item = new Residential();
  delete item;

  print_test( true );
}

void InheritanceTest::check_residential_collect_taxes_empty() {
  print_header( "Checking Residential::collectTaxes() at time 0" );

  Residential residential;

  // This may not pass, but I'm too lazy to deal with floating point comparisons
  print_test( residential.collectTaxes() == 0.0 );
}

void InheritanceTest::check_residential_tick() {
  print_header( "Checking Residential::tick()" );

  Residential residential;
  residential.tick();

  // This may not pass, but I'm too lazy to deal with floating point comparisons
  print_test( residential.collectTaxes() == 0.1 );
}

void InheritanceTest::print_header( string message ) {
  cout << "--- Testing " << message << " ---" << endl;
}

void InheritanceTest::print_test( bool result ) {
  if( result ) {
    cout << "PASS";
  } else {
    cout << "FAIL";
  }

  cout << endl;
}