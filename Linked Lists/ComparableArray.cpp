/*
Adele Noel-Rickert
Creates an array and pass information to comparable and also determines the smallest and largest
*/


#include <iostream>
#include <string>
#include <cstdlib>
#include "ComparableArray.h"
#include "ComparableInt.h"
#include "ComparableString.h"
#include "Comparable.h"
using namespace std;

/*
Comparable** CA;  // Array of Comparable pointers
	int sz; // number of elements in array
*/


// initializes array with size s
ComparableArray::ComparableArray(int s) {
	sz = s;
	CA = new Comparable * [sz];
	for (int i = 0; i < sz; i++) {
		CA[i] = nullptr;
	}

}

//destroys array and everything in it
ComparableArray::~ComparableArray() {
	for (int i = 0; i < sz; i++)
		delete CA[i];
	delete[] CA;

}

//retrieves smallest item in array
Comparable* ComparableArray::smallest() {

	Comparable* smallest = CA[0];
	for (int i = 1; i < sz; i++)
		if (CA[i]->cmp(smallest) == 1)
			smallest = CA[i];
	return smallest;
}

//retrieves largest item in array
Comparable* ComparableArray::largest() {
	Comparable* larger = CA[0];
	for (int i = 1; i < sz; i++)
		if (CA[i]->cmp(larger) == -1)
			larger = CA[i];
	return larger;

}

//puts c in item i of array
void ComparableArray::seti(int i, Comparable* c) {
	CA[i] = c;

}