#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<vector>
#include "draw.h"
using namespace std;

const string hangman[]={
		" -------------    \n"
         	"   |                \n"
                "   |                \n"
                "   |                \n"
                "   |                \n"
                "   |                \n"
                " -----              \n" ,

		"   -------------    \n"
         	"   |           |    \n"
         	"   |                \n"
         	"   |                \n"
         	"   |                \n"
         	"   |                \n"
         	" -----              \n",

        	"   -------------    \n"
       		"   |           |    \n"
       		"   |           O    \n"
   		"   |                \n"
         	"   |                \n"
         	"   |                \n"
        	" -----              \n",

		"   -------------    \n"
         	"   |           |    \n"
         	"   |           O    \n"
         	"   |          /     \n"
         	"   |                \n"
         	"   |                \n"
         	" -----              \n",

		"   -------------    \n"
         	"   |           |    \n"
         	"   |           O    \n"
         	"   |          /|    \n"
         	"   |                \n"
         	"   |                \n"
         	" -----              \n",

         	"   -------------    \n"
         	"   |           |    \n"
         	"   |           O    \n"
         	"   |          /|\\  \n"
        	"   |                \n"
         	"   |                \n"
         	" -----              \n",

         	"   -------------    \n"
         	"   |           |    \n"
         	"   |           O    \n"
         	"   |          /|\\  \n"
         	"   |          /     \n"
         	"   |                \n"
         	" -----              \n",

         	"   -------------    \n"
         	"   |           |    \n"
         	"   |           O    \n"
        	"   |          /|\\  \n"
         	"   |          / \\  \n"
         	"   |                \n"
        	" -----              \n"
};

void renderGame(const string &secretWord, string &guessWord, int &badGuessCount) {
    cout << "Your guess: " << guessWord << endl;
    cout << hangman[badGuessCount];
    return;
}

void displayResult(const string &secretWord, string &guessWord) {
    bool check = 1;
    for(int i = 0 ; i < (int)secretWord.length() ; i++) {
        if(secretWord[i] != guessWord[i]) check = 0;
    }
    if(check == 1) cout << "\nCongratulation! You win!" << endl << "The answer is: " << guessWord;
    else cout << "\nThe answer is: " << secretWord << endl << "You lose! Try again...";
}
