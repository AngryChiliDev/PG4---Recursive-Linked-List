//
//  PG4.cpp
//  PG4 V4 - Fixed delete
//  V3 - Fixed addinorder opperation
//  V2 - Added missing #include <algorithm> to all files. Remove "" if entered.
//
//  Created by Lawrence Johnson on 11/1/14.
//  Copyright (c) 2014 Lawrence Johnson. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "PG4.h"
#include "LL.h"

using namespace std;

int main(){
    LL *books = new LL();
    bool exit = false;
    string title;
    while (exit == false){
        cout << "COMMAND: ";
        getline(cin, title);
        string entered = title;
        transform(entered.begin(), entered.end(), entered.begin(), ::tolower);
        // Command list
        if (entered == "exit") {
            exit = true;
            break;
        }
        else if (entered.substr(0,4) == "add " && entered.length() > 4) {
            if (entered[4] == '"') {    // V2 - Check for "" and remove them
                add(books, title.substr(5, (title.length()-6)));
            }
            else add(books, title.substr(4, title.length()));
        }
        else if (entered == "print") {
            cout << endl;
            books->print();
        }
        else if (entered.substr(0,7) == "remove " && entered.length() > 7) {
            if (entered[7] == '"') {    // V2 - Check for "" and remove them
                remove(books, title.substr(8, (title.length() - 9)));
            }
            else remove(books, title.substr(7, title.length()));
        }
        else cout << "No Command Entered! Please use ADD, REMOVE, PRINT, or EXIT.\n";
    }
    cout << endl;
    
    // Clean up after yourself!
    delete books;
    
    return 0;
}

/*
 Check if book title is already in list. If it is, do nothing.
 Else add the book to the list.
 */
void add(LL *books, string s){
    bool cont = books->check(s);
    if (cont == true) {
        cout << "Book already entered\n";
    }
    else books->addinorder(s);
}

/*
 Remove books with keyword in title
 */
void remove(LL *books, string s){
    books->DelInitial(s);
}
