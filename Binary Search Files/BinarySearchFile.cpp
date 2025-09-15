/*
Adele Noel-Rickert

This program will take in a user file and use binary search to find if a specific user input record is present
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "BinarySearchFile.h"
using namespace std;

int main(int argc, char** argv) {

	string searchword;
	string filename;
	cout << "What is the filename? ";
	cin >> filename;

	int four = firstFour(filename);//takes in the first 4 numbers and stores them in a variable

	int length = fileLength(filename, four);
	
	
	
	
	
	cout << "What word are you looking for? ";
	cin >> searchword;
	//change search word to be all lower
	for (int i = 0; i < searchword.length(); i++) {
		if (searchword[i] >= 'A' && searchword[i] <= 'Z') {
			searchword[i] += 32;
		}
	}

	BinarySearch(filename, searchword, four);



	return 0;
}
//Reads in the first 4 bytes of the file and returns the amount of bytes the rest of the records are
int firstFour(string file) {
	fstream beginning(file, ios::in | ios::out | ios::binary);
	string amount;

	for (int i = 0; i < 4; i++) {
		char ch;
		beginning.get(ch);
		amount += ch;
	}
	int num = stoi(amount);

	beginning.close();

	return num;
}
int fileLength(string fname, int bytelength) {
	fstream fl(fname, ios::in | ios::out | ios::binary);
	fl.seekg(0, ios::end);  //Jump to the end of the file
	int fsz = fl.tellg(); //What byte number am I at?  aka the length of the file
	fsz = fsz - 4;
	int rct = fsz / bytelength;  //How many words are in the file?

	return rct;

}


//reads in the record and returns a string
string ReadRecord(fstream& fl, int rnum, int bytelength){

	int pos = (rnum * bytelength) + 4; 
	fl.seekg(pos);
	string s = "";
	for (int i = 0; i < bytelength; i++) {
		char c;
		//change all words to lower
		fl.get(c);
		if (c >= 'A' && c <= 'Z') {
			c += 32;
		}

		s += c;
	}
	return s;


}


/*
Searches through the file by taking in the low and the high of the file for amount of words
and will look at the median of them. It will then see if the words matches, if not the program will
change the low or the high depending if the word is higher or lower than the median. 
*/
void BinarySearch(string fname, string word, int wordlength) {

	fstream fl(fname, ios::in | ios::out | ios::binary);
	fl.seekg(0, ios::end);  //Jump to the end of the file
	int fsz = fl.tellg(); //What byte number am I at?  aka the length of the file
	int rct = fsz / wordlength;  //How many words are in the file?

	

	
	bool found = false;
	int f = 0, l = rct-1;
	while (f <= l && !found) {
		int t = (f + l) / 2;
		string tempword = ReadRecord(fl, t, firstFour(fname));
		found = word == tempword;
		if (found) cout << "FOUND" << endl;
		else {
			if (word < tempword) {
		
				l = t - 1;
			}
			else {
				
				f = t + 1;
			}
		}
	}
		if (!found) {
			cout << "Not in file" << endl;
		}
	
}


