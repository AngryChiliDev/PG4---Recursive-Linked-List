//
//  LLN.h
//  PG4 V2
//
//  Created by Lawrence Johnson on 10/24/14.
//  Copyright (c) 2014 Lawrence Johnson. All rights reserved.
//

#ifndef _LLN_
#define _LLN_

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>    // V2 added
#include "LL.h"
using namespace std;

class LL;
class LLN {
private:
	string i;
	LLN * next;

public:
	LLN (string I, LLN * n);
	~LLN ();
	string geti ();
	LLN *getnext ();
	void setnext (LLN *n);
	void print ();
	void printall ();
	void addback (string I);
	void addinorder (string I);
	LLN * addinorder_0 (string I);
	LLN * delfirst (string I);
	void delfirst_0 (string I, LLN *prev, LL *l);
    bool dellast (string I, LLN *prev, LL *l);
    LLN * DelInitial (string c);
    bool check(string s);
};


#endif
