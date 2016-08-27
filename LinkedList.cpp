// Programmer:  Alexander Brown
// Student ID: c3260691
// Version: v1.3.4
// Last modified:  27/08/2016

#include "LinkedList.h"
#include "Node.h"

namespace brown_deckofcards {
	
	LinkedList::LinkedList() {
		head = NULL;
		tail = NULL;
		current = NULL;
		listLength = 0;
	}
	
	LinkedList::~LinkedList() {
		
		//check we have data
		if (tail) {
			
			//if there is only one item in the list
			if (head == tail) {
				
				//delete the only item
				delete head;
			} else {
				
				//go to second last item in the list
				current = tail->getPrevious();
				
				//delete the next item
				delete current->getNext();
				
				//if we have more than 1 item left in the list
				while (current != head) {
					
					//move back one
					current = current->getPrevious();
					
					//delete the next item
					delete current->getNext();
				}
				
				//last item needs to be deleted
				delete current;
			}
		}
		
		//reset all the values
		head = NULL;
		tail = NULL;
		current = NULL;
		listLength = 0;
	}
	
	void LinkedList::add(Node::value_type data) {
		
		//create a new node with the data provided
		Node* newNode = new Node(data);
		
		//Check if there is any items in our list
		if (tail) {
			
			//if there is, set the tail's next node to the new node
			tail->setNext(newNode);
			
			//then set the new node's previous to the tail
			newNode->setPrevious(tail);
			
			//next we fix up our pointers
			tail = newNode;
			current = newNode;
		} else {
			
			//if no items in our list, simple, set all our internal pointers to point to the new node
			head = newNode;
			tail = newNode;
			current = newNode;
		}
		
		//now update the length of our list
		recountLength();
	}
	
	void LinkedList::add(Node::value_type data, int index) {
		
		//create node to add with data provided
		Node* newNode = new Node(data);
		
		//check there is some data in the list
		if (tail) {
			
			//Check what the index is to decide what to do with it
			if (index >= length()) {
				
				//if index has not been used yet, add the node to the end
				tail->setNext(newNode);
				newNode->setPrevious(tail);
				tail = newNode;
				current = newNode;
			} else if (index <= 0) { 
			
				//if the index at the front, then add the node to the front
				newNode->setNext(head);
				head->setPrevious(newNode);
				head = newNode;
				current = newNode;
			} else {
				
				//move to the index before the one asked for 
				moveCurrent(index - 1);
				
				//update all the pointers to add the new node in
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
		
		//now update the length of our list
		recountLength();
	}
	
	bool LinkedList::remove(int index) {
		
		//check the node exists
		if (index >= 0 && index < length()) {
			
			//move to the node we want to remove
			moveCurrent(index);
			
			//make sure its not the head, avoiding null references
			if (current != head && current != tail) {
				current->getNext()->setPrevious(current->getPrevious());
				current->getPrevious()->setNext(current->getNext());
			} else if (current == head && current == tail) {
				head = NULL;
				tail = NULL;
			} else if (current == head && current != tail) {
				current->getNext()->setPrevious(NULL);
				head = current->getNext();
			} else if (current != head && current == tail) {
				current->getPrevious()->setNext(NULL);
				tail = current->getPrevious();
			}
			
			//delete node to free space and stop leaks
			delete current;
			
			//reset the current back to the start
			current = head;
			
			//count is wrong since we removed an item, so lets recound it
			recountLength();
			return true;
		} else {
			return false;
		}
	}
	
	int LinkedList::find (Node::value_type data) {
		//make sure we have data to find
		if (length() > 0) {
			
			//start at the start of the list
			int index = 0;
			current = head;
			
			//check the head is not the data we are looking for
			if (current->getData() == data) {
					return index;
			}
			
			//start the loop check
			while (current != tail){
				
				//move to the next node
				index++;
				current = current->getNext();
				
				//check if its the node we are looking for
				if (current->getData() == data) {
					return index;
				}
			}
		} 
		
		//couldnt find it? return -1 to show that
		return -1;
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
		
		//make sure our list length is up to date
		recountLength();
	}
	
	Node::value_type LinkedList::get(int index){
		
		//make sure our index is in range
		if (length() > index && index >= 0) {
			moveCurrent(index);
			return current->getData();
		}
		
		//just return the default value if we can't find a value
		return Node::value_type();
	}
	
	int LinkedList::length() const{
		return listLength;
	}
	
	void LinkedList::moveCurrent(int index) {
		
		//move to the start of the list
		current = head;
			
		//move next for index times
		for (int i = 0; i < index; i++) {
			current = current->getNext();
		}
	}
	
	void LinkedList::recountLength() {
		
		//start with 0
		int total = 0;
		
		//make sure we have items in our list
		if (head) {
			
			//start at the start
			current = head;
			
			//we have one ite already, so increment
			total += 1;
			
			//if we are not at the end of the list
			while (current != tail){
				
				//get the next item
				current = current->getNext();
				
				//increment the counterindex
				total += 1;
			}
		}
		
		//return the number of items counted
		listLength = total;
	}
	
}