#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

// Node class representing singly linked list nodes
class IntSLLNode {
	public: 
		// singly linked node constructor
		IntSLLNode() {
			next = nullptr;
		}

		// singly linked node paramaterized constructor
		IntSLLNode(int i,IntSLLNode *in = nullptr) {
			info  = i;
			next = in;
		}
		// data members used by singly linked list node
		int info;
		IntSLLNode *next;
};

// Singly Linked list class
class IntSLList {
		
		// singly linked list constructor
		// that initializes head and tail pointers to nullptr
		IntSLList() {
			head = tail = nullptr; 
		}
		
		// singly linked list destructor
		~IntSLList();
		
		// isEmpty method checks whether the linked 
		// list is empty or not
		int isEmpty() {	
			return head == nullptr;
		}
		
		// method prototypes
		void addToHead(int);
		void addToTail(int); 
		int deleteFromHead(); // delete the head and return its info
		int deleteFromTail(); // delete the tail and returns its info
		void deleteNode(int); // delete a specific node 
		bool isInList(int) const; // check whether given entry is in singly linked list

		// data members of singly linked list
	private: 
		IntSLLNode *head, *tail;
};

#endif
