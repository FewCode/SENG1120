// Programmer:  Alexander Brown
// Student ID: c3260691
// Version: v1.2
// Last modified:  19/08/2016

#include "Node.h"
#include <string>
using namespace std;
using namespace brown_deckofcards;

namespace brown_deckofcards {
	
	Node::Node(const Node::valueType& data){
		internalData = data;
		next = NULL;
		previous = NULL;
	}
	
	void Node::setNext(Node& node) {
		next = &node;
	}
	
	void Node::setPrevious(Node& node) {
		previous = &node;
	}
	
	void Node::setData(valueType& data) {
		internalData = data;
	}
	
	Node* Node::getNext() {
		return next;
	}
	
	Node* Node::getPrevious() {
		return previous;
	}
	
	Node::valueType Node::getData(){
		return internalData;
	}
	
}