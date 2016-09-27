// Programmer:  Alexander Brown
// Course: SENG1120
// Student ID: c3260691
// Version: v2.0.4
// Last modified:  27/09/2016

#include <iostream> // for cout and endl
#include <cstdlib>  // for srand, rand and atoi
#include <ctime>    // for time
#include "DeckOfCards.h"

#include "HandOfCards.h"

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
	
	//1) Create a new instance of DeckOfCards storing a full deck of cards.
	DeckOfCards* deck = new DeckOfCards();
	
	//2) Create tow instances of HandOfCards, named player1 and dealer
	HandOfCards* player1 = new HandOfCards();
	HandOfCards* dealer = new HandOfCards();
	
	//3)Looping through the player and dealer, give them one card each, facing up.
	//	then give one card to player 1 facing up and one card to the dealer facing down.
	Card card = deck->pop();
	player1->add(card, true);
	
	card = deck->pop();
	dealer->add(card, true);
	
	card = deck->pop();
	player1->add(card, true);
	
	card = deck->pop();
	dealer->add(card, false);
	
	//4) Display each hand's content - for player and dealer - one hand per line using the overloaded 
	//	cout << operator, followed by the number of poijts, in this step you must use count() for the player and dealer
	
	bool exitLoop = false;
	int blackjackPhase = 1;
	while (!exitLoop) {
	
		cout << "Player: " << *player1 << " (" << player1->count() << " points)" << endl;
		cout << "Dealer: " << *dealer << " (" << dealer->count() << " points)" <<  endl;
		
		//5) check if the player or the dealer have a count of 21(ace + 10).
		if (player1->count() == 21 && dealer->countAll() == 21) {
			cout << "Tie! There are no winners.";
			exitLoop = true;
		} else if (player1->count() == 21){
			cout << "The player is the winner!";
			exitLoop = true;
		} else if (dealer->countAll() == 21 || player1->count() > 21){
			cout << "The dealer is the winner!";
			exitLoop = true;
		} else {
			if (blackjackPhase == 1) {
				//6) loop through while it has a hand <21 and ask if the player wants to hit or stand
				if (player1->count() < 21) {
					int userInput;
					
					cout << "Player, do you want to Hit (1) or Stand (2)?" << endl;
					cin >> userInput;
					
					if (userInput == 1) {
						card = deck->pop();
						player1->add(card, true);
					} else {
						blackjackPhase = 2;
					}
				}
			} else if (blackjackPhase == 2) {
				while (blackjackPhase == 2) {
					if (dealer->countAll() <= 16) {
						card = deck->pop();
						dealer->add(card, true);
						if (dealer->countAll() >= 17) {
							blackjackPhase = 3;
						}
					} else {
						blackjackPhase = 3;
					}
				}
				
				dealer->faceUp();
				cout << "Player: " << *player1 << endl;
				cout << "Dealer: " << *dealer <<  endl;
				cout << "(P=" << player1->count() << ")(D=" << dealer->count() << ")" << endl;
				if ((player1->count() > dealer->count() ||  dealer->count() > 21) && player1->count() <= 21) {
					cout << "The Player is the winner." << endl;
					exitLoop = true;
				} else if ((dealer->count() > player1->count() ||  dealer->count() > 21) && dealer->count() <= 21) {
					cout << "The Dealer is the winner." << endl;
					exitLoop = true;
				} else {
					cout << "Tie! There are no winners." << endl;
					exitLoop = true;
				}
			}
		}
	}
	
	
	//exit
	return EXIT_SUCCESS;
}


