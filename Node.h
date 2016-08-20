// Programmer:  Alexander Brown
// Student ID: c3260691
// Version: v1.3
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
		
		Node(const valueType& data = valueType());
		
		void setNext(Node*);
		void setPrevious(Node*);
		void setData(valueType&);
		
		Node* getNext();
		Node* getPrevious();
		valueType getData();
		
	private:
		valueType internalData;
		Node* next;
		Node* previous;
	};
}
#endif