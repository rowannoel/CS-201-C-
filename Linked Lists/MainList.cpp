/*
Adele Noel-Rickert

This is the main program, it takes in a user input and gives it over to the link list
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "MainList.h"
#include "LL.h"
using namespace std;

int main(int argc, char** argv) {
	string entered;
	bool book = true;
	bool charadd = true;
	string empty;
	LL* myList = new LL();

	//This while loop will keep going until the user asks to exit, ensuring that they can do all the commands they need
	while (book) {
		string command, word;

		cout << "Please enter a command: ";
		getline(cin, entered);

		//below sets up what command the user inputted 
		for (int i = 0; i < entered.length(); i++) {
			if (entered[i] != ' ') {
				if(entered[i] >= 'a' && entered[i] <='z')
					entered[i] -= 32;
				command += entered[i];
				
			}
			if (entered[i] == ' ') break;

		}

		word = buildWord(entered);
		

		if (command == "ADD") {
			myList->AddSorted(word);
		}

		if (command == "PRINT") {
			myList->print();
		}

		if (command == "REMOVE") {
			myList->remove(word);
		}


		if (command =="EXIT") {
			book = false;
		}

	}




	return 0;
}

//builds the word to send into the link list
string buildWord(string s) {
	string word;
	int place=0, place2=0, times=0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '"' && times ==0) {
			place = i;
			times++;
		}
		if (s[i] == '"' && times == 1) {
			place2 = i;
		}

	}
	for (int i = place+1; i < place2; i++) {
		word += s[i];
	}
	

	return word;
}
