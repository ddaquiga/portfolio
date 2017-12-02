/*****************************************
 * Darrel Daquigan
 * 915744913
 * darreldaquigan@sfsu.edu
 * Cygwin64 2.2.1
 *****************************************/

#ifndef TREE
#define TREE

#include "node.h"
#include <iostream>

using namespace std;

template <typename T>
class Tree
{
private:
  Node<T>* root;

public:
  ~Tree();

  void insert( T );
  void insertHelp( Node<T>*, T );

  bool contains( T );
  bool containsHelp( Node<T>*, T );

  void remove( T );
  void removeHelp( Node<T>*, T);
  void removeRoot();
  void removeMatch( Node<T>*, Node<T>*, bool );
  T getMinimumValue( Node<T>* );

  bool isFull();
  bool isFullHelp( Node<T>* );

  int height();
  int heightHelp( Node<T>* );

  void preorder();
  void preorderHelp( Node<T>* );

  void inorder();
  void indorderHelp( Node<T>* );

  void postorder();
  void postorderHelp(Node<T>* );
};

template <typename T>
Tree<T>::~Tree()
{
  root = NULL;
}

template <typename T>
void Tree<T>::insert( T value )
{
  if ( root == NULL ){
    root = new Node<T>( value );
  }

  else{
    insertHelp( root, value );
  }
}

template <typename T>
void Tree<T>::insertHelp( Node<T>* parent, T value )
{
  if ( value < parent->data ){
    if ( parent->left == NULL ){
      parent->left = new Node<T>( value );
    }

    else{
      insertHelp( parent->left, value );
    }
  }

  else{
    if ( parent->right == NULL ){
      parent->right = new Node<T>( value );
    }

    else{ 
      insertHelp( parent->right, value );
    }
  }
}

template <typename T>
bool Tree<T>::contains( T value ){
  return containsHelp( root, value );
}

template <typename T>
bool Tree<T>::containsHelp( Node<T>* node, T value ){
  if ( node == NULL ){
    return false;
  }
  else{
    if ( value == node->data ){
      return true;
    }
    else if ( value < node->data ){
      return containsHelp( node->left, value );
    }
    else{
      return containsHelp( node->right, value );
    }
  }
}

template <typename T>
void Tree<T>::remove( T value ){
  removeHelp( root, value );
}

template <typename T>
void Tree<T>::removeHelp( Node<T>* parent, T value ){
  if ( root != NULL ){
    if( root->data == value ){
      removeRoot();
    }
    else{
      if ( value < parent->data && parent->left != NULL ){
        if ( parent->left->data == value ){
          removeMatch( parent, parent->left, true );
        }

        else{
          removeHelp( parent->left, value );
        }
      }

      else if ( value > parent->data && parent->right != NULL ){
        if ( parent->right->data == value ){
          removeMatch( parent, parent->right, false);
        }

        else{
          removeHelp( parent->right, value );
        }
      }
    }
  }
}

template <typename T>
void Tree<T>::removeRoot(){
    Node<T>* trash = root;
    int smallestInRight;
    
    if ( root->left == NULL && root->right == NULL ){
      root = NULL;
      delete trash;
    }

    else if ( root->left == NULL && root->right != NULL ){
      root = root->right;
      trash->right = NULL;
      delete trash;
    }

    else if ( root->left != NULL && root->right == NULL ){
      root = root->left;
      trash->left = NULL;
      delete trash;
    }

    else{
      smallestInRight = getMinimumValue( root->right );
      removeHelp( root, smallestInRight );
      root->data = smallestInRight;
    }
}

template <typename T>
void Tree<T>::removeMatch( Node<T>* parent, Node<T>* node, bool left ){
  if ( root != NULL ){
    Node<T>* trash;
    T smallestInRight;

    // no children
    if ( node->left == NULL && node->right == NULL ){
      trash = node;
      if ( left ){
        parent->left = NULL;
      }
      
      else{
        parent->right = NULL;
      }

      delete trash;
    }

    // right child only
    else if ( node->left == NULL && node->right != NULL ){
      if ( left ){
        parent->left = node->right;
      }

      else{
        parent->right = node->right;
      }

      node->right = NULL;
      trash = node; 
      delete trash;
    }

    //left child only
    else if ( node->left != NULL && node->right == NULL ){
      if ( left ){
        parent->left = node->left;
      }

      else{
        parent->right = node->left;
      }

      node->left = NULL;
      trash = node; 
      delete trash;
    }

    // two children
    else{
      smallestInRight = getMinimumValue( node->right );
      removeHelp( node, smallestInRight );
      node->data = smallestInRight;
    }
  }
}

template <typename T>
T Tree<T>::getMinimumValue( Node<T>* node ){
  if ( node == NULL ){
    return T();
  }

  else{
    if ( node->left == NULL ){
      return node->data;
    }

    else{
      return getMinimumValue( node->left );
    }
  }
}

template <typename T>
bool Tree<T>::isFull(){
  return isFullHelp( root );
}

template <typename T>
bool Tree<T>::isFullHelp( Node<T>* node ){
  if ( node == NULL ){
    return true;
  }

  int count = 0; 

  if ( node->left == NULL ){
    count++;
  }
  
  if ( node->right == NULL ){
    count++;
  }

  return ( count != 1 && isFullHelp( node->left ) &&
    isFullHelp( node->right ) );
}

template <typename T>
int Tree<T>::height(){
  return heightHelp( root );
}

template <typename T>
int Tree<T>::heightHelp( Node<T>* node ){
  if ( node == NULL ){
    return 0;
  }

  int leftCount = heightHelp( node->left );
  int rightCount = heightHelp( node->right );

  if ( leftCount < rightCount ){
    return ( 1 + rightCount );
  }
  else{
    return ( 1 + leftCount );
  }
}

template <typename T>
void Tree<T>::preorder(){
  cout << "preorder ";
  preorderHelp( root );
  cout << '\n';
}

template <typename T>
void Tree<T>::preorderHelp( Node<T>* node ){
  if ( node != NULL ){
    cout << node->data << ' ';
    preorderHelp( node->left );
    preorderHelp( node->right );
  }
}

template <typename T>
void Tree<T>::inorder(){
  cout << "inorder ";
  indorderHelp( root );
  cout << '\n';
}

template <typename T>
void Tree<T>::indorderHelp( Node<T>* node ){
  if ( node != NULL ){
    indorderHelp( node->left );
    cout << node->data << ' ';
    indorderHelp( node->right );
  }
}

template <typename T>
void Tree<T>::postorder(){
  cout << "postorder ";
  postorderHelp( root );
  cout << '\n';
}

template <typename T>
void Tree<T>::postorderHelp( Node<T>* node ){
  if ( node != NULL ){
    postorderHelp( node->left );
    postorderHelp( node->right );
    cout << node->data << ' ';
  }
}


#endif