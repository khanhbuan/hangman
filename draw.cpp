#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<vector>
#include<thread>
#include<chrono>
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

const string figure1[] = {
    "     O     \n"
    "    /|\\   \n"
    "    | |    \n",

    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n",

    "   __O__   \n"
    "     |     \n"
    "    / \\   \n",

    "    \\O/   \n"
    "     |     \n"
    "    / \\   \n",

    "   __O__   \n"
    "     |     \n"
    "    / \\   \n",

    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,

    "    O      \n"
    "    /|\\   \n"
    "    / \\   \n" ,

    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,

    "      O    \n"
    "    /|\\   \n"
    "    / \\   \n" ,

    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,

};

const string figure2[] = {
    "   ------------+    \n"
    "   |    /           \n"
    "   |   O            \n"
    "   |  /|\\          \n"
    "   |  / \\          \n"
    "   |                \n"
    " -----              \n" ,

    "   ------------+    \n"
    "   |     |          \n"
    "   |     O          \n"
    "   |    /|\\        \n"
    "   |    / \\        \n"
    "   |                \n"
    " -----              \n",

    "   ------------+    \n"
    "   |      \\        \n"
    "   |       O        \n"
    "   |      /|\\      \n"
    "   |      / \\      \n"
    "   |                \n"
    " -----              \n",
    "   ------------+    \n"
    "   |     |          \n"
    "   |     O          \n"
    "   |    /|\\        \n"
    "   |    / \\        \n"
    "   |                \n"
    " -----              \n",
};

void renderGame(const string &secretWord, string &guessWord, int &badGuessCount) {
    cout << "Your guess: " << guessWord << endl;
    cout << hangman[badGuessCount];
    return;
}

void displayResult(const string &secretWord, string &guessWord) {
    bool check = true;
    for(int i = 0 ; i < (int)secretWord.length() ; i++) {
        if(secretWord[i] != guessWord[i]) check = 0;
    }
    while(1) {
        for(int i = 1 ; i <= 30 ; i++) cout << endl;
        if(check == true) cout << "\nCongratulation! You win!" << endl << "The answer is: " << guessWord << endl;
        else cout << "\nThe answer is: " << secretWord << endl << "You lose! Try again..." << endl;
        cout << (check == true ? getNextDancingMan() : getNextHangman());
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}


string getNextDancingMan() {
    const int NUMBER_OF_FIGURES1 = sizeof(figure1) / sizeof(string);
    static int current_figure1 = 0;
    return figure1[(current_figure1++) % NUMBER_OF_FIGURES1];
}

string getNextHangman() {
    const int NUMBER_OF_FIGURES2 = sizeof(figure2) / sizeof(string);
    static int current_figure2 = 0;
    return figure2[(current_figure2++) % NUMBER_OF_FIGURES2];
}
