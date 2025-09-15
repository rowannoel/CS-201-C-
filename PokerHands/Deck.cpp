/*
Adele Noel-Rickert
This program builds the deck of the cards
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "Card.h"  
#include "Deck.h"
using namespace std;

//builds the deck
Deck::Deck(int some) {
	amount = some;
	MyCards = new Card * [some];
	for (int i = 0; i < some; i++){
		int enteredNumber;
		cout << "Enter card " << i << ": ";
		cin >> enteredNumber;
		MyCards[i] = new Card(enteredNumber);

		}
	
		
		
	Shuffle();
	
}

//get rids of the deck to avoid memory leaks
Deck::~Deck() {

	for (int i = 0; i < amount; i++)
		delete MyCards[i];
	delete MyCards;
	
}

//shuffles the deck so the cards are in a random order and there are no repeats
void Deck::Shuffle() {

	for (int i = 1; i < amount; i++) {
		int r = rand() % (i + 1);
		Card* t = MyCards[i];
		MyCards[i] = MyCards[r];
		MyCards[r] = t;
	}
}

//prints the amount given
void Deck::printsome() {
	for (int i = 0; i < 5; i++)//change amount to 5
		MyCards[i]->print();
	hand();
}

//takes in what the hand is
void Deck::hand() {
	int* handRank = new int[amount];

	for (int i = 0; i < 5; i++) {
		handRank[i] = MyCards[i]->getrank();
	}


	int* timesAppeared = new int[13];
	for (int i = 0; i < 13; i++) {
		timesAppeared[i] = 0;
	}

	for (int j = 0; j < 5; j++) {
		timesAppeared[handRank[j]]++; //this will look at the number of handRank and go up by 1
		}

	
	
	int* countCount = new int[5];
	for (int i = 0; i < 5; i++) 
		countCount[i] = 0;


	for (int j = 0; j < 13; j++) {
		countCount[timesAppeared[j]]++;
		}



	
	

	for (int i = 1; i < 5; i++) {
		if (countCount[2] == 1 && countCount[3] == 1) {
			cout << "You have a full house" << endl;
			break;
		}
		if (countCount[4] == 1) {
			cout << "You have four of a kind" << endl;
			break;
		}
		if (countCount[3] == 1) {
			cout << "You have three of a kind" << endl;
			break;
		}

		if (countCount[2] == 1) {
			cout << "You have a pair" << endl;
			break;
		}

		if (countCount[2] == 2) {
			cout << "You have 2 pairs" << endl;
			break;
		}

		if (countCount[1] == 5) {//all diff check for the rest
			if (lookSuit() && !stright()) {
				if (Royal()) {
					cout << "You have a Royal Flush" << endl; 
					break;
				}
				else {
					cout << "You have a Flush" << endl;
					break;
				}
			}
			else if (stright()) {
				if (lookSuit()) {
					cout << "You have a Straight Flush" << endl;
					break;
				}
				else {
					cout << "You have a Straight" << endl;
					break;
				}
			}
			else {//everything else failed, time to look at highs.
				if (timesAppeared[0] == 1) { 
					cout << "You have an ACE high" << endl;
					break;
				}
				else if (timesAppeared[12] == 1) {
					cout << "You have an King high" << endl;
					break;
				}
				else if (timesAppeared[11] == 1) {
					cout << "You have an Queen high" << endl;
					break;
				}
				else if (timesAppeared[10] == 1) {
					cout << "You have an Jack high" << endl;
					break;
				}
				else if (timesAppeared[9] == 1) {
					cout << "You have an Ten high" << endl;
					break;
				}
				else if (timesAppeared[8] == 1) {
					cout << "You have an Nine high" << endl;
					break;
				}
				else if (timesAppeared[7] == 1) {
					cout << "You have an Eight high" << endl;
					break;
				}
				else if (timesAppeared[6] == 1) {
					cout << "You have an Seven high" << endl;
					break;
				}
				else {
					cout << "You don't have a hand" << endl;
					break;
				}
			}

		}
	}
		

	delete[] handRank;
	delete[] timesAppeared;
	delete[] countCount;

}
//Looks at the suit of the hand to see if it's the same or not
bool Deck::lookSuit(){

	int* handSuit = new int[4];

	for (int i = 0; i < 4; i++) {
		handSuit[i] = 0;
	}

	for (int i = 0; i < 5; i++) {
		int suits;
		suits = MyCards[i]->getsuit();
		handSuit[suits]++;
	}

	for (int i = 0; i < 5; i++) {
		if (handSuit[i] == 5) {
			return true;
		}
	}
	return false;


	delete[] handSuit;
}

//checks and see if the hand is a straight or not if so returns true
bool Deck::stright() {
	bool check=false;
	int* rankCheck = new int[13];

	for (int i = 0; i < 13; i++) {//initializes the array
		rankCheck[i] = 0;
	}

	for (int i = 0; i < 5; i++) {
		int ranks;
		ranks = MyCards[i]->getrank();

		rankCheck[ranks]++;
	}

	int findOnePos = 0, times=0;
	//finds the position of the first 1 in the array
	for (int i = 0; i < 13; i++) {
		if (rankCheck[i] == 1 && times==0) {
			findOnePos = i;
			times++;
		}
	}


	int spCt = 0;
	if (findOnePos == 0) {
		if (rankCheck[1] != 1) {
			if (rankCheck[9] == 1) {
				for (int i = 9; i < 13; i++) {
					if (rankCheck[i] == 1 && times == 0) {
						spCt++;
					}
					else {
						times++;
					}
				}
			}
		}
	}

	int count = 0;
	for (int i = findOnePos; i < 13; i++) {
		if (rankCheck[i] == 1 && times==0) {
			count++;
		}
		else {
			times++;
		}
	}
	if (count == 5 || spCt == 4) {
		check = true;
	}




	delete[] rankCheck;
	return check;
}

//checks and sees if the hand is a royal if so returns true
bool Deck::Royal() {
	bool roy = false;
	int* rank = new int[13];

	for (int i = 0; i < 13; i++) {
		rank[i] = 0; 
	}

	for (int i = 0; i < 5; i++) {
		int ranks;
		ranks = MyCards[i]->getrank();

		rank[ranks]++;

	}

	//0 , 9 , 10 , 11, 12 
	if (rank[0] == 1 && rank[9] == 1 && rank[10] == 1 && rank[11] == 1 && rank[12] == 1)
		roy = true;


	return roy;
	delete[] rank;
}