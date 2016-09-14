// Programmer:  Alexander Brown
// Course: SENG1120
// Student ID: c3260691
// Version: v2.0.1
// Last modified:  13/09/2016

#include "Card.h"

namespace brown_deckofcards {
	
	Card::Card() {
		face = "";
		value = -1;
		faceUp = false;
	}
	
	Card::Card(string cardFace, int cardValue, bool isCardFaceUp) {
		face = cardFace;
		value = cardValue;
		faceUp = isCardFaceUp;
	}
	
	Card::~Card() {
		//set all our data to their initial values
		face = "";
		value = 0;
		faceUp = false;
	}
	
	void Card::setFaceUp(bool isCardFaceUp) {
		faceUp = isCardFaceUp;
	}
	
	string Card::getFace() const {
		return face;
	}
	
	int Card::getValue() const {
		return value;
	}
	
	bool Card::getFaceUp() const {
		return faceUp;
	}
	
	bool operator== (const Card& card1, const Card& card2){
		return card1.getFace() == card2.getFace();
	}
	
	ostream& operator<<(ostream& out, const Card& c){
		
		//use the getFace method to get our data to print
		out << c.getFace();
		
		//return our output
		return out;
	}
	
}