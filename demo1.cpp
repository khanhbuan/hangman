#include<iostream>
#include<cstring>
#include<ctime>
#include<fstream>
#include<vector>
using namespace std;

const int MAX_BAD_GUESS = 7;
const char* fileNAME = "word.txt";
vector<string> wordList;

string hangman[]={
            	" -------------      \n"
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

void renderGame(const string &secretWord, string &guessWord, int &badGuessCount) {
    cout << "Your guess: " << guessWord << endl;
    cout << hangman[badGuessCount];
    return;
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

bool gameOver(const string &secretWord, string &guessWord, int &badGuessCount) {
    if(badGuessCount >= MAX_BAD_GUESS) return 0;
    bool check = 0;
    for(int i = 0 ; i < (int)secretWord.length() ; i++) {
        if(secretWord[i] != guessWord[i]) check = 1;
    }
    if(check == 0) return 0;
    return 1;
}

void displayResult(const string &secretWord, string &guessWord) {
    bool check = 1;
    for(int i = 0 ; i < (int)secretWord.length() ; i++) {
        if(secretWord[i] != guessWord[i]) check = 0;
    }
    if(check == 1) cout << "\nCongratulation! You win!" << endl << "The answer is: " << guessWord;
    else cout << "\nThe answer is: " << secretWord << endl << "You lose! Try again...";
}

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
