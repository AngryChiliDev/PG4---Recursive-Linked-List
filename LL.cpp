//
//  LL.cpp
//  PG4 V4
//
//  Created by Lawrence Johnson on 11/1/14.
//  Copyright (c) 2014 Lawrence Johnson. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>    // V2 added
#include "LL.h"
#include "LLN.h"
using namespace std;

/*
 Create an empty Linked List
 */
LL::LL () {
	head = NULL;
}
/*
 Delete Linked List
 */
LL::~LL () {
	delete head;
}

/*
 Add string to the front of the Linked List
 */
void LL::addfront (string I) {
	head = new LLN (I,head);
}

/*
 Add string to the back of the Linked List
 */
void LL::addback (string I) {
	if (head==NULL) head = new LLN (I,NULL);
	else head->addback (I);
}

/*
 Print Linked List
 */
void LL::print () {
	if (head != NULL) head->printall ();
	cout << endl;
}

/*
 Add string to the order of lowest to highest to the Linked List
 */
void LL::addinorder (string I) {
	if (!head) head = new LLN (I,NULL);
	else head = head->addinorder_0 (I);
}

/*
 Delete first appearance of a string
 */
void LL::delfirst (string I) {
	if (!head) return;
	head = head->delfirst (I);
}

/*
 Delete first appearance of a string
 */
void LL::delfirst_0 (string I) {
	if (!head) return;
	head->delfirst_0 (I,NULL,this);
}

/*
 Delete first appearance of a string
 */
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
