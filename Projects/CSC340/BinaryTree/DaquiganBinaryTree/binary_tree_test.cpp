#include "binary_tree_test.h"

void BinaryTreeTest::run_tests() {
  test_node_creation_with_value();
  test_node_children_are_null_by_default();

  test_tree_contains();
  test_tree_remove();
  test_tree_height();
  test_tree_is_full();
  test_tree_preorder();
  test_tree_inorder();
  test_tree_postorder();
}

void BinaryTreeTest::test_node_creation_with_value() {
  test_header( "node creation with value" );

  int test_value = 42;
  Node<int> node( test_value );

  print_test( node.data == test_value );
}

void BinaryTreeTest::test_node_children_are_null_by_default() {
  test_header( "node children are null by default" );

  Node<int> node;

  print_test( node.left == NULL && node.right == NULL );
}

void BinaryTreeTest::test_tree_contains() {
  test_header( "tree insert and contains" );

  int something = 42;
  Tree<int> tree;
  tree.insert( something );

  print_test( tree.contains( something ) == true );
}

void BinaryTreeTest::test_tree_remove() {
  test_header( "tree remove" );

  int something = 42;
  Tree<int> tree;
  tree.insert( something );
  tree.remove( something );

  print_test( tree.contains( something ) == false );
}

void BinaryTreeTest::test_tree_height() {
  test_header( "tree height" );

  Tree<int> tree;
  print_test( tree.height() == 0 );

  tree.insert( 10 );
  print_test( tree.height() == 1 );

  tree.insert( 15 );
  print_test( tree.height() == 2 );

  tree.insert( 5 );
  print_test( tree.height() == 2 );
}

void BinaryTreeTest::test_tree_is_full() {
  test_header( "tree is full" );

  Tree<int> tree;
  tree.insert( 50 );
  tree.insert( 100 );
  tree.insert( 25 );
  tree.insert( 12 );
  tree.insert( 35 );
  tree.insert( 30 );
  tree.insert( 40 );

  print_test( tree.isFull() );

  tree.insert( 5 );

  print_test( ! tree.isFull() );
}

void BinaryTreeTest::test_tree_preorder() {
  test_header( "tree traversal: preorder 60 20 10 40 30 50 70" );

  Tree<int> tree = create_tree();
  tree.preorder();
}

void BinaryTreeTest::test_tree_inorder() {
  test_header( "tree traversal: inorder 10 20 30 40 50 60 70" );

  Tree<int> tree = create_tree();
  tree.inorder();
}

void BinaryTreeTest::test_tree_postorder() {
  test_header( "tree traversal: postorder 10 30 50 40 20 70 60" );

  Tree<int> tree = create_tree();
  tree.postorder();
}

Tree<int> BinaryTreeTest::create_tree() {
  Tree<int> tree;

  tree.insert( 60 );
  tree.insert( 70 );
  tree.insert( 20 );
  tree.insert( 40 );
  tree.insert( 10 );
  tree.insert( 50 );
  tree.insert( 30 );

  return tree;
}

void BinaryTreeTest::test_header( string message ) {
  cout << "--- Testing " << message << " ---" << endl;
}

void BinaryTreeTest::print_test( bool result ) {
  if( result ) {
    cout << "PASS";
  } else {
    cout << "FAIL";
  }

  cout << endl << endl;
}