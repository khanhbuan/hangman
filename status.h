#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<vector>
#ifndef STATUS_H
#define STATUS_H
using namespace std;

void chooseWord(const char *fileName);

void initialize(string &secretWord, string &guessWord, int &badGuessCount);

bool gameOver(const string &secretWord, string &guessWord, int &badGuessCount);
#endif // STATUS_H
