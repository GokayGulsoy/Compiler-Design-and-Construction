#ifndef DOUBLYNODE_H
#define DOUBLYNODE_H

// Node class that represents doubly node
template <typename T>
class DoublyNode {
    public:
        T Value;
        DoublyNode<T> *Previous; 
        DoublyNode<T> *Next;       
        DoublyNode(T value);
};

template <typename T>
DoublyNode<T>::DoublyNode(T val)
{
    Value = val;
    Previous = nullptr;
    Next = nullptr;
}

#endif