#include<iostream>
#include<cstring>
#include<ctime>
#include<fstream>
#include<vector>
#include "draw.h"
#include "status.h"
#include "update.h"
using namespace std;

main() {
    srand(time(0));

    string secretWord, guessWord;
    int badGuessCount;
    char ch;

    initialize(secretWord, guessWord, badGuessCount);

    do {
        renderGame(secretWord, guessWord, badGuessCount);
        input(guessWord, ch);
        updateGame(secretWord, guessWord, badGuessCount, ch);
    } while(gameOver(secretWord, guessWord, badGuessCount) == 1);

    displayResult(secretWord, guessWord);
}
