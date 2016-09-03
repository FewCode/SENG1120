// Programmer:  Alexander Brown
// Course: SENG1120
// Student ID: c3260691
// Version: v1.3.6
// Last modified:  03/09/2016

#include "Node.h"

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
	
	ostream& operator<<(ostream& out, const Node& n){
		
		//use the value method to get a formated string to print
		out << n.getData();
		
		//return our output
		return out;
	}
	
}