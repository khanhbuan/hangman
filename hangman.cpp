#include<iostream>
#include<cstring>
#include<ctime>
#define MAX_BAD_GUESS 7
using namespace std;

string words[] = {"angle", "ant", "apple", "arch", "arm", "army",
"baby", "bag", "ball", "band", "basin", "basket", "bath", "bed",
"bee", "bell", "berry", "bird", "blade", "board", "boat", "bone",
"book", "boot", "bottle", "box", "boy", "brain", "brake", "branch",
"brick", "bridge", "brush", "bucket", "bulb", "button", "cake",
"camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
"chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb",
"cord", "cow", "cup", "curtain", "cushion", "dog", "door", "drain", "drawer",
"dress", "drop", "ear", "egg", "engine", "eye", "face", "farm", "feather",
"finger", "fish", "flag", "floor", "fly", "foot", "fork", "fowl", "frame",
"garden", "girl", "glove", "goat", "gun", "hair", "hammer", "hand", "hat",
"head", "heart", "hook", "horn", "horse", "hospital", "house", "island",
"jewel", "kettle", "key", "knee", "knife", "knot", "leaf", "leg", "library",
"line", "lip", "lock", "map", "match", "monkey", "moon", "mouth", "muscle",
"nail", "neck", "needle", "nerve", "net", "nose", "nut", "office", "orange",
"oven", "parcel", "pen", "pencil", "picture", "pig", "pin", "pipe", "plane",
"plate", "plow", "pocket", "pot", "potato", "prison", "pump", "rail", "rat",
"receipt", "ring", "rod", "roof", "root", "sail", "school", "scissors", "screw",
"seed", "sheep", "shelf", "ship", "shirt", "shoe", "skin", "skirt", "snake",
"sock", "spade", "sponge", "spoon", "spring", "square", "stamp", "star", "station",
"stem", "stick", "stocking", "stomach", "store", "street", "sun", "table", "tail",
"thread", "throat", "thumb", "ticket", "toe", "tongue", "tooth", "town", "train",
"tray", "tree", "trousers", "umbrella", "wall", "watch", "wheel", "whip", "whistle",
"window", "wire", "wing", "worm"};
string hang[]={
		"   -------------    \n"
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
         	"   |     	     \n"
         	" -----              \n",

        	"   -------------    \n"
        	"   |           |    \n"
       		"   |           O    \n"
       		"   |                \n"
        	"   |                \n"
         	"   |     	     \n"
        	" -----   	     \n",

		"   -------------    \n"
         	"   |           |    \n"
         	"   |           O    \n"
         	"   |           |    \n"
         	"   |                \n"
         	"   |     	     \n"
         	" -----   	     \n",

		"   -------------    \n"
         	"   |           |    \n"
         	"   |           O    \n"
         	"   |          /|    \n"
         	"   |                \n"
         	"   |     \n"
         	" -----   \n",

         	"   -------------    \n"
         	"   |           |    \n"
         	"   |           O    \n"
         	"   |          /|\\  \n"
        	"   |                \n"
         	"   |    	     \n"
         	" -----   	     \n",

         	"   -------------    \n"
         	"   |           |    \n"
         	"   |           O    \n"
         	"   |          /|\\  \n"
         	"   |          /     \n"
         	"   |     	     \n"
         	" -----   	     \n",


         	"   -------------    \n"
         	"   |           |    \n"
         	"   |           O    \n"
        	"   |          /|\\  \n"
         	"   |          / \\  \n"
         	"   |     	     \n"
        	" -----   	     \n"
};
void initialize(string &secretWord, string &guessWord, int &badGuessCount) {
    secretWord = words[rand() % (sizeof(words) / sizeof(string))];
    guessWord = string(secretWord.length(), '-');
    badGuessCount = 0;
    cout << "Welcome to HANGMAN 0.2" << endl << endl;
    return;
}

void renderGame(string &secretWord, string &guessWord, int &badGuessCount) {
    cout << "Your guess: " << guessWord << endl;
    cout << hang[badGuessCount];
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

void updateGame(string &secretWord, string &guessWord, int &badGuessCount, char &ch) {
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

bool gameOver(string &secretWord, string &guessWord, int &badGuessCount) {
    if(badGuessCount >= MAX_BAD_GUESS) return 0;
    bool check = 0;
    for(int i = 0 ; i < (int)secretWord.length() ; i++) {
        if(secretWord[i] != guessWord[i]) check = 1;
    }
    if(check == 0) return 0;
    return 1;
}

void displayResult(string &secretWord, string &guessWord) {
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
