/*
Adele Noel-Rickert
This program builds the deck of the cards
*/

#ifndef _DECK_
#define _DECK_

#include <iostream>
#include <string>
#include <cstdlib>
#include "Card.h"  //Include Card class since I need it
using namespace std;

class Card;  //Prototype the Card class since I need it
class Deck {

private:
	Card** MyCards; //MyCards is an array of card pointers
	int amount;
public:
	Deck(int some);
	~Deck(); //destructor:  get rid of memory leaks
	void Shuffle();
	void printsome();
	void hand();
	bool lookSuit();
	bool stright();
	bool Royal();


};

#endif

