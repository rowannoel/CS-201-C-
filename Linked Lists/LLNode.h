/*
Adele Noel-Rickert

This is the Link list node, it takes in information from LL and manipulates the list. It then returns it's
info to LL once done.
*/
#ifndef _LLNODE_
#define _LLNODE_

#include <iostream>
#include <string>
#include <cstdlib>
#include "LL.h"
#include "MainList.h"
using namespace std;

class LL;

class LLNode {

private:
	string info;
	LLNode* next;

public:
	LLNode(string s, LLNode* n);
	~LLNode();
	void print();
	LLNode* AddSorted(string s);
	LLNode* remove(string s);
	string getinfo();
	void setnext(LLNode* p);

};

#endif