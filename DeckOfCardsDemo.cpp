// Programmer:  Alexander Brown
// Student ID: c3260691
// Version: v1.3.3
// Last modified:  27/08/2016

#include <iostream> // for cout and endl
#include <cstdlib>  // for srand, rand and atoi
#include <ctime>    // for time
#include "DeckOfCards.h"

using namespace std;
using namespace brown_deckofcards;


/**
 * This is an example program that shows how to seed a random number generator
 * using a number provided from the command line and then access those random numbers.
 *
 * It will use a number provided on the command line (e.g. test_random.exe 12321) if one exists
 * otherwise it will seed the random nmber using the current time in seconds
 *
 * @param argc the number of arguments provided to the main function (this includes the program name itself)
 * @param argv an array of strings containing each of the arguments
 *
 * @author Trent Houliston
 */
int main(int argc, char* argv[]) {

    // Make sure we have at least two arguments
    // The first argument will be the program name e.g. myCode.exe
    // The second argument will be the seed for the random number generator
    if (argc >= 2) {
        // Use atoi (ascii to integer) to convert our argument to a number
        // note that if the user enters an invalid number this will be 0
        int seed = atoi(argv[1]);

        // Use that number to seed the random number generator
        srand(seed);
    }
    // If we don't have at least two arguments seed the random number generator using the current time
    else {
        // Get the current time as an integer
        int seed = time(NULL);

        // Use that number to seed the random number generator
        srand(seed);
    }

	/* Starting my own work
	*/
	
	//1) create a new instance of DeckOfCards storing a full deck of cards 
	DeckOfCards* deckOfCards = new DeckOfCards();
	
	//2) Print the deck of cards using value(). The card values have to
	//		be separated by a single blank space, all in the same line.
	cout << deckOfCards->value() << endl;
	
	//3) Shuffle the deck of cards using shuffle()
	deckOfCards->shuffle();
	
	//4) Print the deck of cards again using cout <<
	cout << *deckOfCards << endl;
	
	//5) Print the position of cards “4-H”, “10-S”, “Q-C” and “A-D”
	cout << "\n*Card Positions*" << endl;
	cout << "4-H: " << deckOfCards->position("4-H") << endl;
	cout << "10-S: " << deckOfCards->position("10-S") << endl;
	cout << "Q-C: " << deckOfCards->position("Q-C") << endl;
	cout << "A-D: " << deckOfCards->position("A-D") << endl;
	
	//6) Print the total number of cards in DeckOfCards using length()
	cout << "Total number of cards: " << deckOfCards->length() << endl;
	
	//7) Remove the cards “4-H” and “10-S”
	deckOfCards->remove("4-H");
	deckOfCards->remove("10-S");
	
	//8) Print the position of cards “4-H”, “10-S”, “Q-C” and “A-D” again 
	cout << "\n*Card Positions*" << endl;
	cout << "4-H: " << deckOfCards->position("4-H") << endl;
	cout << "10-S: " << deckOfCards->position("10-S") << endl;
	cout << "Q-C: " << deckOfCards->position("Q-C") << endl;
	cout << "A-D: " << deckOfCards->position("A-D") << endl;
	
	//9) Print the total number of cards in DeckOfCards using length()
	cout << "Total number of cards: " << deckOfCards->length() << endl;
	
	//10) Reverse DeckOfCards and print its content with the overloaded << operator
	deckOfCards->reverse();
	cout << "\n" << *deckOfCards << endl;
	
	for (int i = 0; i < 1000000; i++) {
		DeckOfCards* deckOfCards2 = new DeckOfCards();
		
		delete deckOfCards2;
	}
	
	//exit
	return EXIT_SUCCESS;
}


