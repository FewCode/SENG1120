// Programmer:  Alexander Brown
// Student ID: c3260691
// Version: v1.3.1
// Last modified:  20/08/2016

#ifndef ALEX_LINKEDLIST
#define ALEX_LINKEDLIST

#include "Node.h"

namespace brown_deckofcards {
class LinkedList
{
	public:
	
		// Precondition:
		// Postcondition: A new empty instance of LinkedList is created with all 
		//	internal pointers being null
		LinkedList();
		
		// Precondition:
		// Postcondition: The data provided will be added to the end list as a new node
		void add(Node::valueType);
		
		// Precondition:
		// Postcondition: The data provided will be added to the the specified index in the list as a new node
		void add(Node::valueType, int);
		
		// Precondition:
		// Postcondition: if the index is valid, the node at that position will be removed from the list 
		// 	and true is returned. If the index is not valid, no nodes are touched and false is returned
		bool remove(int);
		
		// Precondition:
		// Postcondition: If the value is found, the index is returned. If not, then -1 is returned
		int find (Node::valueType);
		
		// Precondition:
		// Postcondition: If both the indexs are valid, the items in the list are swaped. 
		// 	If not, then no items are swaped
		void swap(int, int);
		
		// Precondition: The index provided is valid
		// Postcondition: If the index is valid, the data of the item at that position is returned.
		//	If not, then the default value for the variable is returned
		Node::valueType get(int);
		
		// Precondition:
		// Postcondition: The length of the list is returned
		int length() const;
		
	private:
		Node* head;
		Node* tail;
		Node* current;
		int listLength;
		
		// Precondition: The index must exist (might need to precheck on length)
		// Postcondition: the internal variable current is moved to point to the node at the provided index
		void moveCurrent(int);
		
		// Precondition: 
		// Postcondition: The internal length varible is updated to the current length of the list
		void recountLength();
	};
}
#endif