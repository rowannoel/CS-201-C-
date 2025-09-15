/*
Name: Adele Noel-Rickert
Description: This program will take in a user input checkerboard and see if a piece can make a valid jump
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include "Checkers.h"
using namespace std;

int main(int argc, char** argv) {
	int rows, cols, checkr, checkc;
	string useless;

	srand(time(NULL));

	cout << "How many rows does your checkerboard have? ";
	cin >> rows;
	cout << "How many columns does your checkerboard have? ";
	cin >> cols;

	char** Board;
	Board = new char* [rows];
	for (int i = 0; i < rows; i++)
		Board[i] = new char[cols];


	cout << "Enter your board below: " << endl;
	getline(cin, useless);
	enteredBoard(Board, rows, cols);
	
	
	/*
	cout << "This is the board you entered" << endl;
	PrintBoard(Board, rows, cols);
	*/



	cout << "Please enter row you want checked ";
	cin >> checkr;
	getline(cin, useless);

	cout << "Please enter column you want checked ";
	cin >> checkc;
	getline(cin, useless);

	
	checkJump(Board, rows, cols, checkr, checkc);
		


	for (int i = 0; i < rows; i++)
		delete[] Board[i];
	delete[] Board;


	return 0;
}

//prints the board on the screen
void PrintBoard(char** Board, int rlen, int clen) {

	for (int i = 0; i < rlen; i++) {
		for (int j = 0; j < clen; j++)
			cout << Board[i][j];
		cout << endl;
	}
}

//Takes in the board from a user
void enteredBoard(char** Board, int row, int cols) {
	Write a C++ program using pthreads that performs matrix multiplication in parallel. Read in
integers m, n, and p from standard input; they will each be on their own line. Then read in
floating point numbers for an m x n matrix and an n x p matrix. Each number will be on its own
line. And you should fill the matrices horizontally left-to-right, top row first, bottom row last.
After reading in the numbers, perform the multiplication in parallel, and print out the resulting
matrix.
	

}
//sees if everything is in bounds
bool inBounds(int rlen, int clen, int r, int c) {

	if (r < 0) return false;
	if (r >= rlen) return false;
	if (c < 0) return false;
	if (c >= clen) return false;
	return true;
}
//Checks to see if the piece to jump over is the opposite color
bool oppositeColor(char** Board, int r, int c, int rlen, int clen) {
	
	if (inBounds(rlen, clen, r + 1, c + 1)) {
		if (Board[r][c] == 'R' && Board[r + 1][c + 1] == 'B' && Board[r + 2][c + 2] == ' ') return true;
		if (Board[r][c] == 'B' && Board[r + 1][c + 1] == 'R' && Board[r + 2][c + 2] == ' ') return true;
	}
	if (inBounds(rlen, clen, r + 1, c - 1)) {
		if (Board[r][c] == 'R' && Board[r + 1][c - 1] == 'B' && Board[r + 2][c - 2] == ' ') return true;
		if (Board[r][c] == 'B' && Board[r + 1][c - 1] == 'R' && Board[r + 2][c - 2] == ' ') return true;
	}
	if (inBounds(rlen, clen, r - 1, c - 1)) {
		if (Board[r][c] == 'R' && Board[r - 1][c - 1] == 'B' && Board[r - 2][c - 2] == ' ') return true;
		if (Board[r][c] == 'B' && Board[r - 1][c - 1] == 'R' && Board[r - 2][c - 2] == ' ') return true;
	}
	if (inBounds(rlen, clen, r - 1, c + 1)) {
		if (Board[r][c] == 'R' && Board[r - 1][c + 1] == 'B' && Board[r - 2][c + 2] == ' ') return true;
		if (Board[r][c] == 'B' && Board[r - 1][c + 1] == 'R' && Board[r - 2][c + 2] == ' ') return true;
	}

		
		
		

	return false;
}

//checks to see if the checker can make a valid jump
void checkJump(char** Board, int rlen, int clen, int r, int c) {
	bool canjump = false;

	if (inBounds(rlen, clen, r, c)) {
		

		if (inBounds(rlen, clen, r + 1, c + 1) && inBounds(rlen, clen, r + 2, c + 2) && canjump==false) {
			if (oppositeColor(Board,r,c, rlen, clen)) {
				cout << "The checker at that spot can make a valid jump";
				canjump = true;

			}
		}
		if (inBounds(rlen, clen, r + 1, c - 1) && inBounds(rlen, clen, r + 2, c - 2) && canjump == false) {
			if (oppositeColor(Board, r, c, rlen, clen)) {
				cout << "The checker at that spot can make a valid jump";
				canjump = true;

			}
		}
		if (inBounds(rlen, clen, r - 1, c - 1) && inBounds(rlen, clen, r - 2, c - 2) && canjump == false) {
			if (oppositeColor(Board, r, c, rlen, clen)) {
				cout << "The checker at that spot can make a valid jump";
				canjump = true;

			}
		}
		if (inBounds(rlen, clen, r - 1, c + 1) && inBounds(rlen, clen, r - 2, c + 2) && canjump == false) {
			if (oppositeColor(Board, r, c, rlen, clen)) {
				cout << "The checker at that spot can make a valid jump";
				canjump = true;

			}
		}
		if(canjump==false)
			cout << "The checker cannot make a valid jump";
	}
	
}




