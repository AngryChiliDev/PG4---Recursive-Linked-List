//
//  LL.cpp
//  PG4 V3
//
//  Created by Lawrence Johnson on 10/24/14.
//  Copyright (c) 2014 Lawrence Johnson. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>    // V2 added
#include "LL.h"
#include "LLN.h"
using namespace std;

LL::LL () {
	head = NULL;
}

LL::~LL () {
	delete head;
}

void LL::addfront (string I) {
	head = new LLN (I,head);
}

void LL::addback (string I) {
	if (head==NULL) head = new LLN (I,NULL);
	else head->addback (I);
}

void LL::print () {
	if (head != NULL) head->printall ();
	cout << endl;
}

void LL::addinorder (string I) {
	if (!head) head = new LLN (I,NULL);
	else head = head->addinorder_0 (I);
}

void LL::delfirst (string I) {
	if (!head) return;
	head = head->delfirst (I);
}

void LL::delfirst_0 (string I) {
	if (!head) return;
	head->delfirst_0 (I,NULL,this);
}

void LL::sethead (LLN *h) {head = h;}

/*
 Delete all appearences of a word
 */
void LL::DelInitial (string c) {
    if (head) head = head->DelInitial (c);
}

/*
 Check if the book title already appears in the list
 */
bool LL::check(string s){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    bool match = false;
    if (!head) return match;
    if (head && head->geti() != s) match = head->check(s);
    string temp = head->geti();
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    if (temp == s) {
        return true;
    }
    return match;
}
