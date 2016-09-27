// Programmer:  Alexander Brown
// Course: SENG1120
// Student ID: c3260691
// Version: v2.0.3
// Last modified:  27/09/2016

#ifndef ALEX_HANDOFCARDS
#define ALEX_HANDOFCARDS

#include "LinkedList.h"
#include "Card.h"
using namespace std;

namespace brown_deckofcards {
class HandOfCards
{
	public:
	
		HandOfCards();
		~HandOfCards();
		
		int count();
		int countAll();
		string value();
		void faceUp();
		void add(Card, bool);
		
	private:
		
		LinkedList<Card>* hand;
	};
	
	// The overloaded << operator. Prints out all the cards in the deck in a space seperated string
	// Precondition: The deck of cards is not NULL
	// Postcondition: Prints out the cards in a space sperated string
	ostream& operator << (ostream&, const HandOfCards&);
}
#endif