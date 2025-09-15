/*
Adele Noel-Rickert
This program builds the cards
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "Card.h"
using namespace std;

Card::Card(int v) {

	

	value = v;
	suit = value / 13; 
	rank = value % 13; 
	
	switch (rank) {
	case 0: name = "ACE"; break;
	case 1: name = "TWO"; break;
	case 2: name = "THREE"; break;
	case 3: name = "FOUR"; break;
	case 4: name = "FIVE"; break;
	case 5: name = "SIX"; break;
	case 6: name = "SEVEN"; break;
	case 7: name = "EIGHT"; break;
	case 8: name = "NINE"; break;
	case 9: name = "TEN"; break;
	case 10: name = "JACK"; break;
	case 11: name = "QUEEN"; break;
	case 12: name = "KING"; break;
	}
	name += " OF ";
	switch (suit) {
	case 0: name += "CLUBS"; break;
	case 1: name += "DIAMONDS"; break;
	case 2: name += "HEARTS"; break;
	case 3: name += "SPADES"; break;
	}
	
}

Card::~Card() {
	
}

void Card::print() {
	cout << name << endl;
}
int Card::getrank() { return rank; }
int Card::getsuit() { return suit; }
int Card::getvalue() { return value; }
string Card::getname() { return name; }

void Card::setrank(int i) { rank = i; }
void Card::setsuit(int i) { suit = i; }
void Card::setvalue(int i) { value = i; }
void Card::setname(string s) { name = s; }