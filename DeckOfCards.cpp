// Programmer:  Alexander Brown
// Student ID: c3260691
// Version: v1.3.5
// Last modified:  30/08/2016

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
				
				//ints dont like the be added with strings so an ostreangsteam is used to concatenate
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
	
	DeckOfCards::~DeckOfCards(){
		delete deck;
	}
	
	void DeckOfCards::shuffle() {
		
		//loop through from end to (start + 1)
		for (int i = deck->length() -1; i >= 1; i--) {
			
			//pick a value from the start to the number before j
			int j = (rand()%i);
			
			//swap those two values
			deck->swap(i, j);
		}
	}
	
	int DeckOfCards::length() const{
		
		//The linked list will hold the value of length
		return deck->length();
	}
	
	bool DeckOfCards::empty() const {
		
		//If we have more than 0 items our list is not empty
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
		
		//start with an empty string
		string cards = "";
		
		//loop through all our cards in the deck
		for (int i = 0; i < deck->length(); i++) {
			
			//add the card to the string
			cards = cards + deck->get(i);
			
			//add a space as well if it is not the last item in the list
			if (i < deck->length() - 1) {
				cards = cards + " ";
			}
		}
		
		//return our constructed string
		return cards;
	}
	
	bool DeckOfCards::remove(string cardName) {
		
		//use inbuilt methods in string to find the index of the card and remove it
		return deck->remove(deck->find(cardName));
	}
	
	void DeckOfCards::reverse(){
		
		//create a new empty list
		LinkedList* reversedDeck = new LinkedList();
		
		//add all the items from the old deck to the new deck in reverse order
		for (int i = length() - 1; i >= 0; i--) {
			reversedDeck->add(deck->get(i));
		}
		
		//delete the old deck to stop memory leaks
		delete deck;
		
		//make the old deck point to the new deck
		deck = reversedDeck;
	}
	
	ostream& operator<<(ostream& out, const DeckOfCards& d){
		
		//use the value method to get a formated string to print
		out << d.value();
		
		//return our output
		return out;
	}
}

