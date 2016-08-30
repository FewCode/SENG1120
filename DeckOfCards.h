// Programmer:  Alexander Brown
// Student ID: c3260691
// Version: v1.3.5
// Last modified:  30/08/2016

#ifndef ALEX_DECKOFCARDS
#define ALEX_DECKOFCARDS

#include <string>
#include "LinkedList.h"
using namespace std;

namespace brown_deckofcards {
class DeckOfCards
{
	public:
	
		//Constructor
		//Creates a full deck of cards
		//Precondition
		//Postcondition: A new instance of DeckOfCards is created containing a newly created deck of cards
		DeckOfCards();
		
		//Destructor
		//Destructs the object if deck of cards
		//Precondition
		//Postcondition: Destructs all the data contained in deck of cards
		~DeckOfCards();
		
		// All the cards in the deck are shuffled
		// Precondition: 
		// Postcondition: The deck will be shuffled according to the Yates algorithm
		void shuffle();
		
		// Returns the length of the deck of cards
		// Precondition: 
		// Postcondition: The length of the deck of cards is returned
		int length() const;
		
		// Returns a bool value based on if the deck is empty or not 
		// Precondition: 
		// Postcondition: A false is returned if there are cards in the deck otherwise a true is returned
		bool empty() const;
		
		// Returns a the position of the first card that fits the data provided
		// Precondition: 
		// Postcondition: If the card is found, the position is returned. If not, then -1 is returned
		int position(string);
		
		// Returns a space seperated string of the cards in the deck
		// Precondition: 
		// Postcondition: A space seperated string of the cards in the deck in their current order is returned
		string value() const;
		
		// Removes the first card in the deck that fits the data provided
		// Precondition: 
		// Postcondition: If the card is found, it is removed from the deck and true is returned. If not, then -1 is returned
		bool remove(string);	
		
		
		// Reverses the order of the list
		// Precondition: 
		// Postcondition: The order of the list is reversed.
		void reverse(); 
		
	private:
		LinkedList* deck;
	};
	
	// The overloaded << operator. Prints out all the cards in the deck in a space seperated string
	// Precondition: The deck of cards is not NULL
	// Postcondition: Prints out the cards in a space sperated string
	ostream& operator << (ostream&, const DeckOfCards&);
}
#endif