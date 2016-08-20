// Programmer:  Alexander Brown
// Student ID: c3260691
// Version: v1.3
// Last modified:  20/08/2016

#include "LinkedList.h"
#include "Node.h"

using namespace brown_deckofcards;

namespace brown_deckofcards {
	
	LinkedList::LinkedList() {
		head = NULL;
		tail = NULL;
		current = NULL;
		listLength = 0;
	}
	
	void LinkedList::add(Node::valueType data) {
		Node* newNode = new Node(data);
		if (tail) {
			tail->setNext(newNode);
			newNode->setPrevious(tail);
			tail = newNode;
			current = newNode;
		} else {
			head = newNode;
			tail = newNode;
			current = newNode;
		}
		recountLength();
	}
	
	void LinkedList::add(Node::valueType data, int index) {
		
		//create node to add with data provided
		Node* newNode = new Node(data);
		
		//check there is some data in the list
		if (tail) {
			
			//if index has not been used yet, add the node to the end
			if (index >= length()) {
				tail->setNext(newNode);
				newNode->setPrevious(tail);
				tail = newNode;
				current = newNode;
			} else if (index <= 0) {
				newNode->setNext(head);
				head->setPrevious(newNode);
				head = newNode;
				current = newNode;
			} else {
				moveCurrent(index -1);
				
				current->getNext()->setPrevious(newNode);
				newNode->setNext(current->getNext());
				newNode->setPrevious(current);
				current->setNext(newNode);
				current = newNode;
			}
			
		} else {
			//if no data already, then add
			head = newNode;
			tail = newNode;
			current = newNode;
		}
		recountLength();
	}
	
	void LinkedList::swap(int node1Index, int node2Index) {
		//make sure we can actually swap
		if (node1Index >= 0 && node1Index < length() && node2Index >= 0 && node2Index < length() && node1Index != node2Index) {
			bool node1Head = false;
			bool node2Head = false;
			bool node1Tail = false;
			bool node2Tail = false;
			
			//set up the node references we need
			moveCurrent(node1Index);
			Node* node1 = current;
			moveCurrent(node2Index);
			Node* node2 = current;
			
			//check if one of the nodes we are swaping are the head
			if (node1 == head) {
				node1Head = true;
			} else if (node2 == head) {
				node2Head = true;
			}
			
			//check if one of the nodes we are swaping are the tail
			if (node1 == tail) {
				node1Tail = true;
			} else if (node2 == tail) {
				node2Tail = true;
			}
			
			//Swap the next node's previous node
			//if its the tail, the getNext returns null, so setting the previous will crash
			if (!node1Tail) {
				node1->getNext()->setPrevious(node2);
			}
			if (!node2Tail) {
				node2->getNext()->setPrevious(node1);
			}
			
			//Swap our node's next pointers
			if (!node1Tail) {
				current = node1->getNext();
			}
			if (!node2Tail) {
				node1->setNext(node2->getNext());
			} else {
				node1->setNext(NULL);
			}
			
			if (!node1Tail) {
				node2->setNext(current);
			} else {
				node2->setNext(NULL);
			}
			
			
			//swap the previous nodes around
			if (!node2Head) {
				current = node2->getPrevious();
			}
			
			if (!node2Head) {
				node2->getPrevious()->setNext(node1);	
			}
			if (!node1Head) {
				node2->setPrevious(node1->getPrevious());
			} else {
				node2->setPrevious(NULL);
			}
			
			if (!node1Head) {
				node1->getPrevious()->setNext(node2);
			}
			
			if (!node2Head) {
				node1->setPrevious(current);
			} else {
				node1->setPrevious(NULL);
			}
			
			//if one node is the head then we have to swap it with the other one
			if (node1Head) {
				head = node2;
			} else if (node2Head) {
				head = node1;
			}
			
			//if one node is the tail then we have to swap it with the other one
			if (node1Tail) {
				tail = node2;
			} else if (node2Tail) {
				tail = node1;
			}
		}
		recountLength();
	}
	
	
	Node::valueType LinkedList::get(int index){
		if (length() > index) {
			moveCurrent(index);
			return current->getData();
		}
		return Node::valueType();
	}
	
	
	int LinkedList::length() const{
		return listLength;
	}
	
	void LinkedList::moveCurrent(int index) {
		current = head;
			
		for (int i = 0; i < index; i++) {
			current = current->getNext();
		}
	}
	
	void LinkedList::recountLength() {
		int total = 0;
		if (head) {
			current = head;
			total += 1;
			
			while (current != tail){
				current = current->getNext();
				total += 1;
			}
		}
		listLength = total;
	}
	
}