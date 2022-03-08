#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<vector>
#include<thread>
#include<chrono>
#include "status.h"
using namespace std;

const int MAX_BAD_GUESS = 7;
const char* fileNAME = "word.txt";
vector<string> wordList;

void chooseWord(const char *fileName) {
    ifstream file(fileName);
    if(file.is_open()) {
        string word;
        while(file >> word) {
            wordList.push_back(word);
        }
    file.close();
    }
}

void initialize(string &secretWord, string &guessWord, int &badGuessCount) {
    chooseWord(fileNAME);
    int index = rand() % wordList.size();
    secretWord = wordList[index];
    guessWord = string(secretWord.length(), '-');
    badGuessCount = 0;
    cout << "Welcome to HANGMAN 0.2" << endl << endl;
    return;
}

bool gameOver(const string &secretWord, string &guessWord, int &badGuessCount) {
    if(badGuessCount >= MAX_BAD_GUESS) return 0;
    bool check = 0;
    for(int i = 0 ; i < (int)secretWord.length() ; i++) {
        if(secretWord[i] != guessWord[i]) check = 1;
    }
    if(check == 0) return 0;
    return 1;
}
