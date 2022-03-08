#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<vector>
#include<thread>
#include<chrono>
#ifndef UPDATE_H
#define UPDATE_H
using namespace std;

void updateGame(const string &secretWord, string &guessWord, int &badGuessCount, char &ch);

void input(string &guessWord, char &ch);

#endif // UPDATE_H
