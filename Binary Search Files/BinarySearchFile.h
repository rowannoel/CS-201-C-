/*
Adele Noel-Rickert

This program will take in a user file and use binary search to find if a specific user input record is present
*/

#ifndef _BINARY_
#define _BINARY_

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv);
int firstFour(string file);
void BinarySearch(string fname, string word, int wordlength);
string ReadRecord(fstream& fl, int rnum, int bytelength);
int fileLength(string fname, int bytelength);

#endif