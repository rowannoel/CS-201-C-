/*
Adele Noel-Rickert

This is the link list, it deals only with the head, then tells LLNode to do the rest
and returns all it's info to the MainList
*/

#ifndef _LL_
#define _LL_

#include <iostream>
#include <string>
#include <cstdlib>
#include "LLNode.h"
using namespace std;

class LLNode;

class LL {

private:
	LLNode* head;
public:
	LL();
	~LL();
	void AddSorted(string s);
	void print();
	void remove(string s);
	void sethead(LLNode* p);


};


#endif
