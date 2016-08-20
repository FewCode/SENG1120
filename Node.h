// Programmer:  Alexander Brown
// Student ID: c3260691
// Version: v1.3.1
// Last modified:  20/08/2016

#ifndef ALEX_NODE
#define ALEX_NODE

#include <string>
using namespace std;

namespace brown_deckofcards {
class Node
{
	public:
		typedef string valueType;
		
		// Precondition:
		// Postcondition: A new instance of Node is created with the provided data
		// and has its next and previous Nodes pointing to NULL
		Node(const valueType& data = valueType());
		
		// Precondition: 
		// Postcondition: The next Node will point towards the provided Node
		void setNext(Node*);
		
		// Precondition:
		// Postcondition: The provious Node will point towards the provided Node
		void setPrevious(Node*);
		
		// Precondition:
		// Postcondition: The internal data will be a copy of the data provided
		void setData(valueType&);
		
		// Precondition: next has been initialised
		// Postcondition: A pointer to the next Node will be returned
		//	possible for the next node to be null
		Node* getNext();
		
		// Precondition: previous has been initialised
		// Postcondition: A pointer to the previous Node will be returned.
		//	possible for the previous node to be null
		Node* getPrevious();
		
		// Precondition: internalData has been initialised
		// Postcondition: The internal data is returned
		valueType const getData() const;
		
	private:
		valueType internalData;
		Node* next;
		Node* previous;
	};
}
#endif