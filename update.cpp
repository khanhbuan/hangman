#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<vector>
#include<thread>
#include<chrono>
#include "update.h"
using namespace std;

void updateGame(const string &secretWord, string &guessWord, int &badGuessCount, char &ch) {
    bool check = 0;
    for(int i = 0 ; i < (int)secretWord.length() ; i++) {
        if(ch == secretWord[i]) {
            check = 1;
            guessWord[i] = ch;
        }
    }
    if(check == 1) cout << "That's right!" << endl;
    if(check == 0) badGuessCount++;
}

void input(string &guessWord, char &ch) {
    cout << "\nEnter your guess: ";
    cin >> ch;
    ch = tolower(ch);
    while(guessWord.find_first_of(ch) != string::npos || ((ch < 'a' || 'z' < ch) && (ch < 'A' || 'Z' < ch))) {
        cout << "invalid character! Please retype: ";
        cin >> ch;
    }
    return;
}
