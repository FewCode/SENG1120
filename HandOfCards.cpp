// Programmer:  Alexander Brown
// Course: SENG1120
// Student ID: c3260691
// Version: v2.0.5
// Last modified:  01/10/2016

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
		
		// loop through all the cards in the hand
		for (int i = 0; i < hand->length(); i++) {
			
			// get a copy of the card
			Card card = hand->get(i);
			
			// check if it is face up
			if (card.getFaceUp()) {
				
				// add the card's value to the total
				totalCount += card.getValue();
			}
		}
		
		// return the total
		return totalCount;
	}
	
	int HandOfCards::countAll() {
		int totalCount = 0;
		
		// loop through all the cards in the hand
		for (int i = 0; i < hand->length(); i++) {
			
			// get a copy of the card
			Card card = hand->get(i);
			
			// add the card's value to the total
			totalCount += card.getValue();
		}
		
		// eturn the total
		return totalCount;
	}
	
	string HandOfCards::value() const {
		string cards = "";
		
		// loop through all the cards in the hand
		for (int i = 0; i < hand->length(); i++) {
			
			// get a copy of the card
			Card card = hand->get(i);
			
			// check if it is face up
			if (card.getFaceUp()) {
				
				// if so, add the card's face to the string
				cards += " " + card.getFace();
			} else {
				
				// if not, add an unknown indicator to the string
				cards += " ?-?";
			}
		}
		
		// return the constructed string
		return cards;
	}
	
	void HandOfCards::faceUp() {
		
		// loop through all the cards in the hand
		for (int i = 0; i < hand->length(); i++) {
			
			// get a copy of the card
			Card card = hand->get(i);
			
			// check if it is face up
			if (!card.getFaceUp()) {
				
				//if not, set our copy of the card to face up.
				card.setFaceUp(true);
				
				//remove the real card
				hand->remove(i);
				
				//add our flipped up copy back in
				hand->add(card, i);
			} 
		}
	}
	
	void HandOfCards::add(Card card, bool facedUp) {
		
		//make sure its face up or not
		card.setFaceUp(facedUp);
		
		//add the card
		hand->add(card);
	}
	
	ostream& operator<<(ostream& out, const HandOfCards& h){
		
		
		out << h.value();
		
		//return our output
		return out;
	}
	
}