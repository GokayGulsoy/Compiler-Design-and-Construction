#include <iostream>
#include "intSLList.h"

// implementation of destructor
IntSLList::~IntSLList() {
	for (IntSLLNode *p; !isEmpty(); ) {
		p = head->next; 
		delete head;
		head = p;
	}
}

// implementation of insertion as head of 
// singly linked list 
void IntSLList::addToHead(int el) {
	head = new IntSLLNode(el,head);
	if (tail == nullptr) {
		tail = head;
	}
}

// implementation of insertion as tail of
// singly linked list
void IntSLList::addToTail(int el) {
	if (tail != nullptr) { // if list is not empty
		tail->next = new IntSLLNode(el);
		tail = tail->next;
	}
	
	else {
		head = tail = new IntSLLNode(el);
	}
}

// implementation of deleting head node
// from singly linked list 
int IntSLList::deleteFromHead() {
	int el = head->info; 
	IntSLLNode *temp = head;
	if (head == tail) { // if only one node in the list 
		head = tail = nullptr; 
	}
	
	else {
		head = head->next; 
	}
	
	delete temp;
	return el;
}

// implementation of deleting node from tail 
// of a singly linked list
int IntSLList::deleteFromTail() {
	int el = tail->info;

	if (head == tail) { // if only one node in the list
		delete head; 
		head = tail = nullptr;
	}

	else { // if more than one node in the linked list
		IntSLLNode *tmp; // find the predecessor of tail
		for (tmp = head; tmp->next != tail; tmp=tmp->next);
		delete tail; 
		tail = tmp; 
		tail->next = nullptr;
	}

	return el;
}

// implementing deletion of a specific node 
// from singly linked list
void IntSLList::deleteNode(int el) {
	if (head != 0) {// if nonempty list
		if (head == tail && el == head->info) { // if only one node in the list
			delete head;
			head = tail = nullptr; 
		}
	
		else if (el == head->info) { // if more than one node in the list
			IntSLLNode *tmp = head;
			head = head->next;
			delete tmp; // and old head is deleted 
		}

		else {
			IntSLLNode *pred, *tmp;
			for (pred = head,tmp = head->next; tmp != nullptr && !(tmp->info == el); pred = pred->next, tmp = tmp->next); 
			if (tmp != nullptr) {
				pred->next = tmp->next;
				
				if (tmp == tail) {
					tail = pred; 
				}
				
				delete tmp;
			}

		}

	}

}

// searching for a particular node in the
// singly linked list
bool IntSLList::isInList(int el) const {
	IntSLLNode *tmp;
	for (tmp = head; tmp != nullptr && ! (tmp->info == el); tmp=tmp->next);
	return tmp != nullptr;
}
