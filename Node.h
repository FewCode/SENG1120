// Programmer:  Alexander Brown
// Course: SENG1120
// Student ID: c3260691
// Version: v1.3.6
// Last modified:  03/09/2016

#ifndef ALEX_NODE
#define ALEX_NODE

#include <string>
using namespace std;

namespace brown_deckofcards {
class Node
{
	public:
		typedef string value_type;
		
		// The constructor
		// Creates a new Node with the data provided
		// Precondition:
		// Postcondition: A new instance of Node is created with the provided data
		// and has its next and previous Nodes pointing to NULL
		Node(const value_type& data = value_type());
		
		// The destructor
		// Deletes the internal data in this Node
		// Precondition:
		// Postcondition: The internal data of the Node is destroyed
		~Node();
		
		// Mutator method
		// Overwrites the pointer to the next node
		// Precondition: 
		// Postcondition: The next Node will point towards the provided Node
		void setNext(Node*);
		
		// Mutator method
		// Overwrites the pointer to the previous node
		// Precondition:
		// Postcondition: The provious Node will point towards the provided Node
		void setPrevious(Node*);
		
		// Mutator method
		// Overwrites the data contained in the node
		// Precondition:
		// Postcondition: The internal data will be a copy of the data provided
		void setData(value_type&);
		
		// Accessor method
		// Returns a pointer to the next node
		// Precondition: next has been initialised
		// Postcondition: A pointer to the next Node will be returned
		//	possible for the next node to be null
		Node* getNext() const;
		
		// Accessor method
		// Returns a pointer to the previous node
		// Precondition: previous has been initialised
		// Postcondition: A pointer to the previous Node will be returned.
		//	possible for the previous node to be null
		Node* getPrevious() const;
		
		// Accessor method
		// Returns a the data contained in the node
		// Precondition: internalData has been initialised
		// Postcondition: The internal data is returned
		value_type const getData() const;
		
	private:
		value_type internalData;
		Node* next;
		Node* previous;
	};
	
	// The overloaded << operator. Prints out all the cards in the deck in a space seperated string
	// Precondition: The deck of cards is not NULL
	// Postcondition: Prints out the cards in a space sperated string
	ostream& operator << (ostream&, const Node&);
}
#endif