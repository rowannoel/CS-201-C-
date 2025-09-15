/*
Adele Noel-Rickert

This is the main program, it is the persons hand and can tell you what the hand is

*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Hand.h"
#include "Card.h"
#include "Deck.h"
using namespace std;

int main(int argc, char** argv) {

	srand(time(NULL));{
		int amount;
		cout << "How many cards are there? ";
		cin >> amount;

		Deck* d = new Deck(amount);
		d->printsome();

		delete d;  
		return 0;
	}
}
