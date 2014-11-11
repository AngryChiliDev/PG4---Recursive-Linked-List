//
//  LLN.cpp
//  PG4 V4 - Modified delInitial to proporly delete all instances of the word
//  V3 - Corrected variable mistype in addinorder_0
//
//  Created by Lawrence Johnson on 11/1/14.
//  Copyright (c) 2014 Lawrence Johnson. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>    // V2 added
#include "LLN.h"
using namespace std;

/*
 Create new node with i = I and next = n
 */
LLN::LLN (string I, LLN * n) { i = I; next = n;}

/*
 Destructor
 */
LLN::~LLN () {

	delete next;
}

/*
 Get i variable
 */
string LLN::geti () {return i;}

/*
 Get next variable
 */
LLN * LLN::getnext () {return next;}

/*
 Set next variable
 */
void LLN::setnext (LLN *n) {next = n;}

/*
 Print i
 */
void LLN::print() {
	cout << i << " ";
}

/*
 Prints current node and passes tells next node to print
 */
void LLN::printall () {
	print ();
    cout << endl;
	if (next) next->printall ();
}

/*
 Add string to the back of the list
 */
void LLN::addback (string I) {
	if (next==NULL) next = new LLN (I,NULL);
	else next->addback (I);
}

/*
 Add string in a smallest to largest order
 */
LLN * LLN::addinorder_0 (string I) {
    string temp = i;
    string temp2 = I;   // V3 - variable set to i instead of I
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    transform(temp2.begin(), temp2.end(), temp2.begin(), ::tolower);
	if (temp > temp2) return new LLN (I,this);
	if (!next) {next = new LLN (I,NULL); return this;}
	next = next->addinorder_0 (I);
	return this;
}

/*
 Delete first instance of a the passed string
 */
LLN * LLN::delfirst (string I) {
	if (i==I) {
		LLN *t = next;
		next = NULL;
		delete this;
		return t;
	}
	if (next) next = next->delfirst (I);
	return this;
}

/*
 Delete last instance of a the passed string
 */
void LLN::delfirst_0 (string I, LLN *prev, LL *l) {
	if (i==I) {
		if (!prev) l->sethead (this->next);
		else prev->setnext (this->next);
		next = NULL;
		delete this;
	} else
		if (next) next->delfirst_0 (I,this,l);
}

/*
 Delete last instance of a the passed string
 */
bool LLN::dellast (string I, LLN *prev, LL *l) {
	bool del = false;
	if (next) del = next->dellast (I,this,l);
	if (del) return true;
	if (i==I) {
		if (!prev) l->sethead (this->next);
		else prev->setnext (this->next);
		next = NULL;
		delete this;
		return true;
	} 
	return false;
}

/*
 Delete all appearences of a word
 */
LLN * LLN::DelInitial (string c) {
    if (next) next = next->DelInitial (c);
    string temp = i;
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    transform(c.begin(), c.end(), c.begin(), ::tolower);    // V4 added to make sure comparisons are all lower cased.
    if (temp.find(c) != string::npos) {
            LLN *t = next;
            next = NULL;
            delete this;
            return t;
    }
    return this;
}

/*
 Check if the book title already appears in the list
 */
bool LLN::check(string s){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    bool match = false;
    if (!next) match = false;
    if (next && i != s) match = next->check(s);
    string temp = i;
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    if (temp == s) {
        return true;
    }
    return match;
}
