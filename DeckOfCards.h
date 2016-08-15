// Programmer:  Alexander Brown
// Student ID: c3260691
// Version: v1.0
// Last modified:  15/08/2016



#ifndef ALEX_DECKOFCARDS
#define ALEX_DECKOFCARDS

#include <string>
using namespace std;

namespace brown_deckofcards {
class DeckOfCards
{
	public:
		//Constructor
		//Creates a full deck of cards
		//?? - Shuffles
		//Precondition
		//Postcondition: A new instance of DeckOfCards is created containing a newly created deck of cards
		DeckOfCards();
		
		void shuffle();
		int length();
		bool empty();
		int position(string);
		string value();
		bool remove(string);	
		void reverse(); //not sure if void
	};
}
#endif