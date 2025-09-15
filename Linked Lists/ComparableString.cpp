/*
Adele Noel-Rickert
Inherites from comparable and stores strings from the array
*/



#include <iostream>
#include <string>
#include <cstdlib>
#include "ComparableString.h"
#include "Comparable.h"
#include "ComparableArray.h"
using namespace std;
/*
string s; //String stored in object
*/

//Constructor
ComparableString::ComparableString(string S) {
	s = S;

}

//Inherited from Comparable
int ComparableString::cmp(Comparable* c) {
	// if a < b, a->cmp (b) should return a negative number <-- for changing out largest
	// if a > b, a->cmp (b) should return a positive number <-- for changing out smallest
	// if a = b, a->cmp (b) should return zero
	ComparableString* a = (ComparableString*)c;

	string a2 = a->gets();
	string s2 = s;

	for (int i = 0; i < s2.length(); i++) {
		if (s2[i] >= 'a' && s2[i] <= 'z')
			s2[i] -= 32;
	}
	for (int i = 0; i < a2.length(); i++) {
		if (a2[i] >= 'a' && a2[i] <= 'z')
			a2[i] -= 32;
	}

	if (a2< s2) return -1;
	if (a2> s2) return 1;
	if (a2 == s2) return 0;


	return 0;
}

//Inherited from Comparable
void ComparableString::print() {
	cout << s << " ";
}

//Retrieves string
string ComparableString::gets() {
	return s;
}
