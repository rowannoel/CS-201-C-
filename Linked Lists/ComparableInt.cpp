/*
Adele Noel-Rickert
Inherites from comparable and stores integers from the array
*/


#include <iostream>
#include <string>
#include <cstdlib>
#include "ComparableInt.h"
#include "Comparable.h"
#include "ComparableArray.h"
using namespace std;
/*
int i; //The integer stored in the object
*/

//Constructor
ComparableInt::ComparableInt(int I) {
	i = I;

}

//Inherited from Comparable
int ComparableInt::cmp(Comparable* c) {
	// if a < b, a->cmp (b) should return a negative number
	// if a > b, a->cmp (b) should return a positive number
	// if a = b, a->cmp (b) should return zero
	ComparableInt* a = (ComparableInt*)c;
	if (a->geti() < i) return -1;
	if (a->geti() > i) return 1;
	if (a->geti() == i) return 0;

	return 0;
}

//Inherited from Comparable
void ComparableInt::print() {
	cout << i << " ";
}

//retrieves integer
int ComparableInt::geti() {
	return i;

}