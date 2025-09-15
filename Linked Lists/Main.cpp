/*
Adele Noel-Rickert
This is the main program that passes information to comparablearray and prints out information
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "Main.h"
#include "ComparableString.h"
#include "ComparableArray.h"
#include "ComparableInt.h"
using namespace std;

int main(int argc, char** argv) {
	int size = 0;
	Comparable* c = nullptr;
	string useless;

	srand(time(NULL));
	cout << "How many intergers?";
	cin >> size;
	ComparableArray* a = new ComparableArray(size);

	for (int i = 0; i < size; i++) {
		int temp;

		cout << "Enter an interger: ";
		cin >> temp;
		ComparableInt* c = new ComparableInt(temp);

		a->seti(i, c);

		
	}
	Comparable* small = a->smallest();
	Comparable* large = a->largest();
	cout << "The smallest int is ";
	small->print();
	cout << "and the largest int is ";
	large->print();
	cout<<"." << endl;

	cout << "How many Strings?";
	cin >> size;
	ComparableArray* b = new ComparableArray(size);
	getline(cin, useless);


	for (int i = 0; i < size; i++) {
		string temp;
		cout << "Enter a string: ";
		getline(cin, temp);
		ComparableString*c = new ComparableString(temp);

		b->seti(i, c);

	}
	Comparable* small2 = b->smallest();
	Comparable* large2 = b->largest();
	cout << "The smallest string is ";
	small2->print();
	cout << "and the largest string is ";
	large2->print();
	cout << "." << endl;


	delete[] a;
	delete[] b;
	
	return 0;

}