// Programmer:  Alexander Brown
// Course: SENG1120
// Student ID: c3260691
// Version: v2.0.3
// Last modified:  27/09/2016

#include "HandOfCards.h"
#include <iostream> // for cout and endl and string

namespace brown_deckofcards {
	
	HandOfCards::HandOfCards() {
		hand = new LinkedList<Card>();
	}
	
	
	HandOfCards::~HandOfCards(){
		delete hand;
	}
	
	int HandOfCards::count() {
		int totalCount = 0;
		
		for (int i = 0; i < hand->length(); i++) {
			Card card = hand->get(i);
			if (card.getFaceUp()) {
				totalCount += card.getValue();
			}
		}
		
		return totalCount;
	}
	
	int HandOfCards::countAll() {
		int totalCount = 0;
		
		for (int i = 0; i < hand->length(); i++) {
			Card card = hand->get(i);
			totalCount += card.getValue();
		}
		
		return totalCount;
	}
	
	string HandOfCards::value() {
		string cards = "";
		
		for (int i = 0; i < hand->length(); i++) {
			Card card = hand->get(i);
			if (card.getFaceUp()) {
				cards += " " + card.getFace();
			} else {
				cards += " ?-?";
			}
		}
		
		return cards;
	}
	
	void HandOfCards::faceUp() {
		
		for (int i = 0; i < hand->length(); i++) {
			Card card = hand->get(i);
			if (!card.getFaceUp()) {
				card.setFaceUp(true);
				hand->remove(i);
				hand->add(card, i);
			} 
		}
	}
	
	void HandOfCards::add(Card card, bool facedUp) {
		card.setFaceUp(facedUp);
		hand->add(card);
	}
	
	ostream& operator<<(ostream& out, const HandOfCards& h){
		
		
		out << "test";
		
		//return our output
		return out;
	}
	
}