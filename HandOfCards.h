// Programmer:  Alexander Brown
// Course: SENG1120
// Student ID: c3260691
// Version: v2.0.5
// Last modified:  01/10/2016

#ifndef ALEX_HANDOFCARDS
#define ALEX_HANDOFCARDS

#include "LinkedList.h"
#include "Card.h"
using namespace std;

namespace brown_deckofcards {
class HandOfCards
{
	public:
	
		// The constructor
		// Creates a new empty HandOfCards.
		// Precondition:
		// Postcondition: A new empty instance of HandOfCards is created.
		HandOfCards();
		
		// The destructor
		// Deletes the internal data in this HandOfCards.
		// Precondition:
		// Postcondition: The internal data of the HandOfCards is destroyed.
		~HandOfCards();
		
		// Counts the values of the cards in this hand of cards, but only the face up ones.
		// Precondition: 
		// Postcondition: The sum of all the values of the cards is returned, but only the face up cards.
		int count();
		
		// Counts the values of the cards in this hand of cards.
		// Precondition: 
		// Postcondition:  The sum of all the values of the cards is returned.
		int countAll();
		
		// Returns a the cards in a space sperated string.
		// Precondition: 
		// Postcondition:  Returns a the cards in a space sperated string with face down cards replaced with "?-?".
		string value() const;
		
		// Turns all the cards face up
		// Precondition: 
		// Postcondition: All cards will be marked face up
		void faceUp();
		
		// Adds a card to the HandOfCards
		// Precondition: The card being added is initialized
		// Postcondition: The card will be added to the handofcards either face up or face down depending on what the bool is 
		void add(Card, bool);
		
	private:
		
		LinkedList<Card>* hand;
	};
	
	// The overloaded << operator. Prints out all the cards in the hand in a space seperated string
	// Precondition: The hand of cards is not NULL
	// Postcondition: Prints out the cards in a space sperated string
	ostream& operator << (ostream&, const HandOfCards&);
}
#endif