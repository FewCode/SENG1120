// Programmer:  Alexander Brown
// Course: SENG1120
// Student ID: c3260691
// Version: v2.0.2
// Last modified:  18/09/2016

#ifndef ALEX_CARD
#define ALEX_CARD

#include <string>
using namespace std;

namespace brown_deckofcards {
class Card
{
	public:
		
		// The constructor
		// Creates a new Card with the data provided
		// Precondition:
		// Postcondition: A new instance of Card is created with the provided data
		Card();
		
		Card(string, bool);
		
		// The constructor
		// Creates a new Card with the data provided
		// Precondition:
		// Postcondition: A new instance of Card is created with the provided data
		Card(string, int, bool);
		
		// The destructor
		// Deletes the internal data in this Card
		// Precondition:
		// Postcondition: The internal data of the Card is destroyed
		~Card();
		
		void setFaceUp(bool);
		
		string getFace() const;
		int getValue() const;
		bool getFaceUp() const;
		
		
		
	private:
		string face;
		int value;
		bool faceUp;
		
		int calculateValue(const string) const;
	};
	
	// The overloaded << operator. Prints out all the cards in the deck in a space seperated string
	// Precondition: The card is not NULL
	// Postcondition: Prints out the value of card
	ostream& operator << (ostream&, const Card&);
	
	bool operator== (const Card&, const Card&);
}
#endif