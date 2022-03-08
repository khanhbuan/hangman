#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<vector>
#ifndef DRAW_H
#define DRAW_H
using namespace std;

void renderGame(const string &secretWord, string &guessWord, int &badGuessCount);

void displayResult(const string &secretWord, string &guessWord);
#endif // DRAW_H
