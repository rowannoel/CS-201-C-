/*
Adele Noel-Rickert

This is the link list, it deals only with the head, then tells LLNode to do the rest
and returns all it's info to the MainList
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "LL.h"
#include "LLNode.h"
using namespace std;

//sets up the head
LL::LL() {

	head = nullptr;  
}

//deletes head
LL::~LL() {

	delete head;
}

//adds a string to the linked list, maintaining the list in alphabetical order
void LL::AddSorted(string s) {
    

    if (!head) head = new LLNode(s, nullptr);
    else head = head->AddSorted(s); 
}

//prints head and on down so long as it is pointing to something
void LL::print() {

	if (head != nullptr) head->print();
	cout << endl;
}

//this removes the node whose value is s.  
void LL::remove(string s) {

    if (!head) return;    
    head = head->remove(s);
    if(head) head = head->remove(s); 


}

//sets head to p if we remove the head in LLNode
void LL::sethead(LLNode* p) {

    head = p;
}


