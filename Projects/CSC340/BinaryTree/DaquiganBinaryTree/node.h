#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node {
  public:
    Node();
    Node( T );
    ~Node();

    T data;
    Node<T> * left;
    Node<T> * right;
};

// Implement this
template <typename T>
Node<T>::Node() {
	data = T();
	left = NULL;
	right = NULL;
}

template <typename T>
Node<T>::Node( T value ) {
	data = value;
	left = NULL;
	right = NULL;

}

template <typename T>
Node<T>::~Node() {
	delete left;
	delete right;
}

#endif