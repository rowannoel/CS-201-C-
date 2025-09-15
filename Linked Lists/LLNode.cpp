/*
Adele Noel-Rickert

This is the Link list node, it takes in information from LL and manipulates the list. It then returns it's 
info to LL once done.
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include "LLNode.h"
#include "LL.h"
#include "MainList.h"
using namespace std;

//creates the list
LLNode::LLNode(string s, LLNode* n) {

	info = s;
	next = n;
}

//deletes the list
LLNode::~LLNode() {

	delete next;
}

//prints everything in the list
void LLNode::print() {

	cout << info;
	if (next != nullptr) {
		cout << " ==> ";
		next->print();
	}
}
LLNode* LLNode::AddSorted(string s) {
    //this will add the node to the list and will return the new "head." (It will return the "head"
    //of the list beginning with me.
    //Is there something we can check before even checking whether we have a next?
    //Even without checking my next, I can test whether the "new guy" will
        //be first in the list.

    if (s < info) { 

        LLNode* newguy = new LLNode(s, this); 
        return newguy;
    }
    if (!next) {
        next = new LLNode(s, nullptr);
        return this;
    }

    next = next->AddSorted(s);
    return this;
}

//Removes all instances of string s. 
LLNode* LLNode::remove(string s) {

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 32;
    }
    string infos = info;
    int pos = -1;

    for (int i = 0; i < infos.length(); i++) {
        if (infos[i] >= 'a' && infos[i] <= 'z')
            infos[i] -= 32;
    }
    pos = infos.find(s, 0);

    if (next)  next = next->remove(s);
    if (pos >-1) { //If I am the node that needs to be deleted
        LLNode* newhead = next;
        next = nullptr;
        delete this;  //At this point, I can't use my own stuff.
        return newhead;
    }
    
    if (!next) return this; 
    

    return this;  


}

//gets the info string
string LLNode::getinfo() {

    return info;
}

//sets up a new next to p
void LLNode::setnext(LLNode* p) {

    next = p;
}

