#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<vector>
#include<thread>
#include<chrono>
#ifndef DRAW_H
#define DRAW_H
using namespace std;

void renderGame(const string &secretWord, string &guessWord, int &badGuessCount);

void displayResult(const string &secretWord, string &guessWord);

string getNextDancingMan();

string getNextHangman();
#endif // DRAW_H
