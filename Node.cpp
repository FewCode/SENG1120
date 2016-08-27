// Programmer:  Alexander Brown
// Student ID: c3260691
// Version: v1.3.4
// Last modified:  27/08/2016

#include "Node.h"
using namespace std;

namespace brown_deckofcards {
	
	Node::Node(const Node::value_type& data) {
		internalData = data;
		next = NULL;
		previous = NULL;
	}
	
	Node::~Node() {
		next = NULL;
		previous = NULL;
	}
	
	void Node::setNext(Node* node) {
		next = node;
	}
	
	void Node::setPrevious(Node* node) {
		previous = node;
	}
	
	void Node::setData(value_type& data) {
		internalData = data;
	}
	
	Node* Node::getNext() const {
		return next;
	}
	
	Node* Node::getPrevious() const {
		return previous;
	}
	
	Node::value_type const Node::getData() const {
		return internalData;
	}
	
}