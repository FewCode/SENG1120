// Programmer:  Alexander Brown
// Student ID: c3260691
// Version: v1.0
// Last modified:  15/08/2016

#include "DeckOfCards.h"
#include <iostream> // for cout and endl
#include <string>

using namespace std;

namespace brown_deckofcards {
	DeckOfCards::DeckOfCards(){
		//TODO: implement constructor
	}
	
	void DeckOfCards::shuffle() {
		//TODO: implement shuffle
		//Must use the Yates algorithm
	}
	
	int DeckOfCards::length(){
		//TODO: implement length
		return 0;
	}
	
	bool DeckOfCards::empty() {
		//TODO: implement empty
		return false;
	}
	
	int DeckOfCards::position(string cardName) {
		//TODO: implement position
		return 0;
	}
	
	string DeckOfCards::value(){
		//TODO: implement value
		return "";
	}
	
	bool DeckOfCards::remove(string cardName) {
		//TODO: implement remove
		return false;
	}
	
	void DeckOfCards::reverse(){
		//TODO: implement reverse
	}
	
	ostream& operator<<(ostream& out, const DeckOfCards& d){
		out << "test" << d << endl;
		return out;
	}
}

