//
//  LL.h
//  PG4 V3
//
//  Created by Lawrence Johnson on 10/24/14.
//  Copyright (c) 2014 Lawrence Johnson. All rights reserved.
//

#ifndef _LL_
#define _LL_

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>    // V2 added
#include "LLN.h"
using namespace std;

class LLN;
class LL {

private:
	LLN *head;

public:
	LL ();
	~LL();
	void addfront (string I);
	void addback (string I);
	void addinorder (string I);
	void print ();
	void delfirst (string I);
	void delfirst_0 (string I);
	void sethead (LLN *h);
    void DelInitial (string c);
    bool check(string s);
};
#endif
