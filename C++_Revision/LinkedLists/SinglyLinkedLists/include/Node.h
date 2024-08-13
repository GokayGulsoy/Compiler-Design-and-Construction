#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

// class that represents a singly node
template <typename T>
class Node
{
public:
    T Value;
    Node<T> *Next;
    // node class constructor
    Node(T value);
};

template <typename T>
Node<T>::Node(T val)
{
    Value = val;
    Next = nullptr;
}

#endif