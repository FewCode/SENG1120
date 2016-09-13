// Programmer:  Alexander Brown
// Course: SENG1120
// Student ID: c3260691
// Version: v2.0.0
// Last modified:  12/09/2016

#include "Card.h"

namespace brown_deckofcards {
	
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
	
	ostream& operator<<(ostream& out, const Card& c){
		
		//use the getFace method to get our data to print
		out << c.getFace();
		
		//return our output
		return out;
	}
	
}