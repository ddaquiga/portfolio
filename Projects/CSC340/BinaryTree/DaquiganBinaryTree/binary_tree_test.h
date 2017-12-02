#ifndef __BINARY_TREE_TEST__
#define __BINARY_TREE_TEST__

#include <iostream>
#include <string>

#include "node.h"
#include "tree.h"

using namespace std;

class BinaryTreeTest {
  public:
    void run_tests();

    void test_node_creation_with_value();
    void test_node_children_are_null_by_default();

    void test_tree_contains();
    void test_tree_remove();
    void test_tree_height();
    void test_tree_is_full();
    void test_tree_preorder();
    void test_tree_inorder();
    void test_tree_postorder();

  private:
    void test_header( string );
    void print_test( bool );

    Tree<int> create_tree();
};

#endif