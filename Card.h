// Programmer:  Alexander Brown
// Course: SENG1120
// Student ID: c3260691
// Version: v2.0.5
// Last modified:  01/10/2016

#ifndef ALEX_CARD
#define ALEX_CARD

#include <string>
using namespace std;

namespace brown_deckofcards {
class Card
{
	public:
		
		// The constructor
		// Creates a new empty Card
		// Precondition:
		// Postcondition: A new empty instance of Card is created
		Card();
		
		
		// The constructor
		// Creates a new Card with the data provided
		// Precondition:
		// Postcondition: A new instance of Card is created with the provided data. 
		// 	Auto calculates the value of the card based on the face provided
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
		
		// Flips the card face up
		// Precondition:
		// Postcondition: the card will be face up
		void setFaceUp(bool);
		
		// Gets the face of the card
		// Precondition:
		// Postcondition: returns the face of the card stored in face
		string getFace() const;
		
		// Gets the face of the card
		// Precondition:
		// Postcondition: returns the value of the card
		int getValue() const;
		
		// gets wether the card is face up or not
		// Precondition:
		// Postcondition: returns wether the card is face up or not
		bool getFaceUp() const;
		
		
		
	private:
		string face;
		int value;
		bool faceUp;
		
		//calculates the value of the card based on what the face of the card is
		int calculateValue(const string) const;
	};
	
	// The overloaded << operator. Prints out all the cards in the deck in a space seperated string
	// Precondition: The card is not NULL
	// Postcondition: Prints out the value
	ostream& operator << (ostream&, const Card&);
	
	bool operator== (const Card&, const Card&);
}
#endif