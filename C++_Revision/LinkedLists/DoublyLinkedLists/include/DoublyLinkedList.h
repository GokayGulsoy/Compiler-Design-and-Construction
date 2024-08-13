#ifndef DOUBLYLINKED_LIST_H
#define DOUBLYLINKED_LIST_H

#include <iostream>
#include "DoublyNode.h"

using namespace std;

// class that represents doubly linked list class
template <typename T>
class DoublyLinkedList {
    private:
        int m_count;
    
    public:
        // first node in the list
        // or null if empty
        DoublyNode<T> *Head;
        // last node in the list
        // or null if empty
        DoublyNode<T> *Tail;

        // Constructor
        DoublyLinkedList();
        // Get() operation
        DoublyNode<T> * Get(int index);

        // Insert operation
        void InsertHead(T val);
        void InsertTail(T val); 
        void Insert(int index,T val);

        // Search operation
        int Search(T val); 

        // Remove() operation 
        void RemoveHead();
        void RemoveTail();
        void Remove(int index);

        // Additional operations
        int Count();
        void PrintList();
        void PrintListBackward();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    // constructor that initializes
    // Head and Tail to NULL and number 
    // of elements in doubly linked list to zero
    Head = nullptr;
    Tail = nullptr;
    m_count = 0;
}

template <typename T>
DoublyNode<T> * DoublyLinkedList<T>::Get(int index)
{
    // Check if the index is out of bound
    if (index <  0 || index > m_count) {
        return nullptr;
    }

    // Start from the Head
    DoublyNode<T> *node = Head;
    // Iterate through the linked list elements
    // until it finds the selected index
    for (int i = 0; i < index ;i++) {
        node = node->Next;
    }

    return node;
}

template <typename T>
int DoublyLinkedList<T>::Search(T val) 
{
    // if linked list is empty, 
    // just return not found
    if (m_count == 0) 
    {
        return -1;
    }

    // Need to count the index 
    int index = 0;
    // Traverse from the Head node
    DoublyNode<T> *node = Head;
    // Traverse until the selected value is matched 
    // with the selected value of the current position
    while (node->Value != val) {
        index++;
        node = node->Next;
    }

    // This will happen if the selected 
    // value is not found
    if (node == nullptr) {
        return -1;
    }

    return index;
}

template <typename T>
void DoublyLinkedList<T>::RemoveTail() 
{
    // Do nothing if list is empty
    if (m_count == 0)
        return;
    
    // If list element is only one
    // just simply call RemoveHead() 
    if (m_count == 1) {
        RemoveHead();
        return;
    }

    // Save the current Tail
    // to a new node
    DoublyNode<T>* node = Tail;
    // Point the Tail Pointer
    // to the element before the current Tail
    Tail = Tail->Previous; 
    // Set the new Next pointer of the new Tail
    // to NULL since we are going to delete the last element 
    Tail->Next = nullptr; 
    // Noew it's safe to remove 
    // the last element
    delete node;
    // One element is removed
    m_count--;
} 

template <typename T> 
void DoublyLinkedList<T>::RemoveHead() 
{
    // Do nothing if list is empty
    if (m_count == 0)
        return;
    
    // Save the current Head 
    // to a new node
    DoublyNode<T>* node = Head;
    // Point the Head Pointer
    // to the next to the current Head
    Head = Head->Next;
    // Now it's safe to remove
    // the first element 
    delete node; 
    // if there's still any element in the list
    // the previous pointer of the Head should
    // point to NULL
    if (Head != nullptr) {
        Head->Previous = nullptr;
    }

    // One element is removed
    m_count--;
}

template <typename T>
void DoublyLinkedList<T>::Remove(int index)
{
    // Do nothing if list is empty
    if (m_count == 0)
        return;
    
    // Do nothing if index is out of bound
    if (index < 0 || index >= m_count) {
        return;
    }

    // if removing the current Head
    if (index == 0) {
        RemoveHead();
        return;
    }

    // if removing the current Tail
    if (index == m_count-1) {
        RemoveTail();
        return;
    }

    // Start to traverse the list
    // from Head
    DoublyNode<T> *prevNode = Head;

    // Find the element before 
    // the selected index
    for (int i = 0; i < index -1; i++) {
        prevNode = prevNode->Next;
    }

    // The removed element is after 
    // the prevNode
    DoublyNode<T> *node = prevNode->Next;
    // The nextNode will be the neighbor of
    // prevNode if the is removed
    DoublyNode<T> *nextNode = node->Next;
    // Link the prevNode to nextNode
    prevNode->Next = nextNode;
    nextNode->Previous = prevNode;

    // It's now safe to remove the selected index element
    delete node;
    // One element is removed 
    m_count--;
}

template <typename T>
void DoublyLinkedList<T>::InsertHead(T val)
{
    // Create a new Node
    DoublyNode<T> *node = new DoublyNode<T>(val);

    // The current Head will no longer become a Head
    // so that the next pointer of the new Node will
    node->Next = Head;

    // if the current Head is exist,
    // the Previous pointer of the current Head
    // should point to the node
    if (Head != nullptr) {
        Head->Previous = node;
    }

    // The new Node now become the Head
    Head = node;
    // if the linked list is empty 
    // The Tail is also the Head
    if (m_count == 0) {
        Tail = Head;
    }

    // One element is added 
    m_count++;
} 

template <typename T>
void DoublyLinkedList<T>::InsertTail(T val) 
{
    // if the linked list is empty 
    // just simply invoke InsertHead() 
    if (m_count == 0) {
        InsertHead(val);
        return;
    }

    // Create a new Node 
    DoublyNode<T> *node = new DoublyNode<T>(val);
    // The current Tail will no longer become a Tail
    // so that the next pointer of the current Tail will
    // point to the new node
    Tail->Next = node;
    // Also, the previous pointer of the new node 
    // should point to the current Tail
    node->Previous = Tail;
    // The new Node become the Tail
    Tail = node;
    // One element is added 
    m_count++;
}

template <typename T>
void DoublyLinkedList<T>::Insert(int index,T val) 
{
    // Check if the index is out of bound
    if (index < 0 || index > m_count) {
        return; 
    }

    // if inserting a new Head
    if (index == 0) {
        InsertHead(val);
        return;
    }

    // if inserting a new Tail
    else if (index == m_count) {
        InsertTail(val);
        return;
    }

    // Start to find previous node
    // from the Head
    DoublyNode<T> *prevNode = Head;
    // Traverse the elements until 
    // the selected index is found
    for (int i = 0; i < index; i++) {
        prevNode = prevNode->Next;
    }

    // Create the next node which is
    // the element after previous node
    DoublyNode<T> *nextNode = prevNode->Next;

    // Create a new Node
    DoublyNode<T> *node = new DoublyNode<T>(val);
    // Insert this new node between
    // the previous node and next node
    node->Next = nextNode;
    node->Previous = prevNode;
    prevNode->Next = node;
    nextNode->Previous = node;

    // One element is added

}

template <typename T>
void DoublyLinkedList<T>::PrintList() 
{
    DoublyNode<T> *node = Head;

    // Traverse all doubly linked list
    // and display each node's value
    while (node != nullptr) {
        std::cout << node->Value << " -> ";
        node = node->Next;
    }

    cout << "NULL" << endl;
}

template <typename T>
void DoublyLinkedList<T>::PrintListBackward()
{
    DoublyNode<T> *node = Tail;
    // Traversing the doubly linked list backward
    while (node != nullptr) {
        cout << node->Value << " -> ";
        node = node->Previous;
    }

    cout << "NULL" << endl;
}

template <typename T>
int DoublyLinkedList<T>::Count()
{
    int count = 0;
    // Traverse the doubly linked list 
    // and count the number of entries 
    DoublyNode<T> *node = Head;
    while (node != nullptr) {
        count++;
        node = node->Next;
    }

    return count;
}

#endif
