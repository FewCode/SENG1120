// Programmer:  Alexander Brown
// Course: SENG1120
// Student ID: c3260691
// Version: v1.3.4
// Last modified:  27/08/2016

#ifndef ALEX_LINKEDLIST
#define ALEX_LINKEDLIST

#include "Node.h"

namespace brown_deckofcards {
class LinkedList
{
	public:
	
		// The constructor
		// Creates a new LinkedList containing no items 
		// Precondition:
		// Postcondition: A new empty instance of LinkedList is created with all 
		//	internal pointers being null
		LinkedList();
		
		// The desctructor
		// Deletes all the data contained in the list
		// Precondition:
		// Postcondition: Every Node in the list will be deleted
		~LinkedList();
		
		// Adds the data to the end of list 
		// Precondition:
		// Postcondition: The data provided will be added to the end list as a new node
		void add(Node::value_type);
		
		// Adds the data to the list at the index provided
		// Precondition:
		// Postcondition: The data provided will be added to the the specified index in the list as a new node
		void add(Node::value_type, int);
		
		// Removes the item at the index provided
		// Precondition:
		// Postcondition: if the index is valid, the node at that position will be removed from the list 
		// 	and true is returned. If the index is not valid, no nodes are touched and false is returned
		bool remove(int);
		
		// Returns the index of the first item that matches the data provided
		// Precondition:
		// Postcondition: If the value is found, the index is returned. If not, then -1 is returned
		int find (Node::value_type);
		
		// Swaps two items in the list
		// Precondition:
		// Postcondition: If both the indexs are valid, the items in the list are swaped. 
		// 	If not, then no items are swaped
		void swap(int, int);
		
		// Gets the data from the specified index
		// Precondition: The index provided is valid
		// Postcondition: If the index is valid, the data of the item at that position is returned.
		//	If not, then the default value for the variable is returned
		Node::value_type get(int);
		
		// Returns the length of the list
		// Precondition:
		// Postcondition: The length of the list is returned
		int length() const;
		
	private:
		Node* head;
		Node* tail;
		Node* current;
		int listLength;
		
		// Moves the current pointer to the specified index
		// Precondition: The index must exist (might need to precheck on length)
		// Postcondition: the internal variable current is moved to point to the node at the provided index
		void moveCurrent(int);
		
		// Used to make sure the length of the list is up to date. Should be called after adding or removing an item in the list
		// Precondition: 
		// Postcondition: The internal length varible is updated to the current length of the list
		void recountLength();
	};
}
#endif