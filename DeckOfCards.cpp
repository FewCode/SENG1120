// Programmer:  Alexander Brown
// Student ID: c3260691
// Version: v1.3
// Last modified:  20/08/2016

#include "DeckOfCards.h"
#include <iostream> // for cout and endl
#include <string>
#include <sstream>

using namespace std;

namespace brown_deckofcards {
	DeckOfCards::DeckOfCards(){
		//TODO: implement constructor
		deck = new LinkedList();
		for (int i = 0; i <= 3; i++) {
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
			
			for(int j = 2; j <= 10; j++) {
				std::ostringstream oss;
				oss << j << "-" << suit;
				deck->add(oss.str());
			}
			deck->add("J-" + suit);
			deck->add("Q-" + suit);
			deck->add("K-" + suit);
			deck->add("A-" + suit);
		}
	}
	
	void DeckOfCards::shuffle() {
		//TODO: implement shuffle
		//Must use the Yates algorithm
	}
	
	int DeckOfCards::length(){
		
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
		//TODO: implement position
		return 0;
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
		//TODO: implement remove
		return false;
	}
	
	void DeckOfCards::reverse(){
		//TODO: implement reverse
	}
	
	ostream& operator<<(ostream& out, const DeckOfCards& d){
		cout << "\n\nPrinting all items in deck" << endl;
		cout << d.value() << endl;
		
		return out;
	}
}

