// Programmer:  Alexander Brown
// Student ID: c3260691
// Version: v1.3
// Last modified:  20/08/2016



#ifndef ALEX_LINKEDLIST
#define ALEX_LINKEDLIST

#include "Node.h"

namespace brown_deckofcards {
class LinkedList
{
	public:
		LinkedList();
		
		void add(Node::valueType);
		void add(Node::valueType, int);
		void swap(int, int);
		Node::valueType get(int);
		int length() const;
		
	private:
		Node* head;
		Node* tail;
		Node* current;
		int listLength;
		
		//must pre-check to make sure index exists
		void moveCurrent(int);
		void recountLength();
	};
}
#endif