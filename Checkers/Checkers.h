#ifndef PG1_h
#define PG1_h

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv);
void PrintBoard(char** Board, int rlen, int clen);
void enteredBoard(char** Board, int row, int cols);
bool inBounds(int rlen, int clen, int r, int c);
void checkJump(char** Board, int rlen, int clen, int r, int c);
bool oppositeColor(char** Board, int r, int c, int rlen, int clen);

#endif