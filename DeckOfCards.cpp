// Programmer:  Alexander Brown
// Student ID: c3260691
// Version: v1.3.1
// Last modified:  20/08/2016

#include "DeckOfCards.h"
#include <iostream> // for cout and endl
#include <cstdlib>  // for srand, rand and atoi
#include <string>
#include <sstream>

using namespace std;

namespace brown_deckofcards {
	DeckOfCards::DeckOfCards(){
		
		//create the empty list
		deck = new LinkedList();
		
		//start looping for each suit
		for (int i = 0; i <= 3; i++) {
			
			//pick what suit goes for what number
			string suit = "";
			switch (i) {
				case 0:
					suit = "S";
					break;
				case 1:
					suit = "H";
					break;
				case 2:
					suit = "C";
					break;
				case 3:
					suit = "D";
					break;
			}
			
			//add the numbers 2 to 10 to the deck
			for(int j = 2; j <= 10; j++) {
				std::ostringstream oss;
				oss << j << "-" << suit;
				deck->add(oss.str());
			}
			
			//add the face cards to the deck
			deck->add("J-" + suit);
			deck->add("Q-" + suit);
			deck->add("K-" + suit);
			deck->add("A-" + suit);
		}
	}
	
	void DeckOfCards::shuffle() {
		for (int i = deck->length() -1; i >= 1; i--) {
			int j = (rand()%i);
			deck->swap(i, j);
		}
	}
	
	int DeckOfCards::length(){
		
		//the linked list will hold the value of length
		return deck->length();
	}
	
	bool DeckOfCards::empty() {
		if (length() > 0) {
			return false;
		} else {
			return true;
		}
	}
	
	int DeckOfCards::position(string cardName) {
		
		//the linked list can find it for us
		return deck->find(cardName);
	}
	
	string DeckOfCards::value() const {
		string cards = "";
		for (int i = 0; i < deck->length(); i++) {
			cards = cards + deck->get(i);
			if (i < deck->length() -1) {
				cards = cards + ", ";
			}
		}
		return cards;
	}
	
	bool DeckOfCards::remove(string cardName) {
		return deck->remove(deck->find(cardName));
	}
	
	void DeckOfCards::reverse(){
		//TODO: implement reverse
	}
	
	ostream& operator<<(ostream& out, const DeckOfCards& d){
		cout << "\n\nPrinting all items in deck" << endl;
		cout << d.value();
		
		return out;
	}
}

