// Programmer:  Alexander Brown
// Course: SENG1120
// Student ID: c3260691
// Version: v2.0.5
// Last modified:  01/10/2016

#include "Card.h"

namespace brown_deckofcards {
	
	Card::Card() {
		
		// set default values
		face = "";
		value = calculateValue("");
		faceUp = false;
	}
	
	Card::Card(string cardFace, bool isCardFaceUp) {
		
		// use the provided data as initial data
		face = cardFace;
		faceUp = isCardFaceUp;
		
		// calculate the value of the card based on the face provided
		value = calculateValue(cardFace);
	}
	
	Card::Card(string cardFace, int cardValue, bool isCardFaceUp) {
		
		// use the provided data as initial data
		face = cardFace;
		value = cardValue;
		faceUp = isCardFaceUp;
	}
	
	Card::~Card() {
		// set all our data to their initial values
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
	
	int Card::calculateValue(const string face) const {
		
		// if the face is blank send an error message
		if (face == "") {
			return -1;
		} else {
			
			// Get the first character of the face to check.
			// The First character determines the card value.
			//		Face cards are 10, so J, Q, K
			//		Ace is 11, so A
			//		10 is valued at 10, but since we are getting the first character it is 1. so 1 is valued 10
			//		All other numbers are their own value
			char firstCharacter = face.at(0);
			if (firstCharacter == '1' || firstCharacter == 'J' || firstCharacter == 'Q' || firstCharacter == 'K') {
				return 10;
			} else if (firstCharacter == 'A') {
				return 11;
			} else if (firstCharacter == '2') {
				return 2;
			} else if (firstCharacter == '3') {
				return 3;
			} else if (firstCharacter == '4') {
				return 4;
			} else if (firstCharacter == '5') {
				return 5;
			} else if (firstCharacter == '6') {
				return 6;
			} else if (firstCharacter == '7') {
				return 7;
			} else if (firstCharacter == '8') {
				return 8;
			} else if (firstCharacter == '9') {
				return 9;
			}
		}
		
		
		return 0;
	}
	
	bool operator== (const Card& card1, const Card& card2){
		
		//compare faces
		return card1.getFace() == card2.getFace();
	}
	
	ostream& operator<<(ostream& out, const Card& c){
		
		//use the getFace method to get our data to print
		out << c.getFace();
		
		//return our output
		return out;
	}
	
}