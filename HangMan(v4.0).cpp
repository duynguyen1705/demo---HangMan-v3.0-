#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <fstream>
#include <algorithm>
#include<thread>
#include<chrono>
#include<windows.h>

using namespace std;

const int maxWrongCount = 7;
void printFigure(int wrongCount);
string chooseWord();
bool check(string computerWord, char guessWord);
string update(string guessedWord, char guessWord, string computerWord);
void printResult();
void renderGame(string guessedWord);
char readGuessWord();
void TextColor(int x);
void clearScreen();
void replay();
void playGame();

int main()
{
    playGame();
    replay();

    return 0;
}

void replay()
{
    char c;
    do{
        cout << "do you want to play again(Y/N): ";
        cin >> c;
    } while(c != 'Y' && c != 'N');
    if (c == 'Y') {
        clearScreen();
        playGame();
    }
    else cout << "Game over!! Hope you a good day <3";
}
void playGame()
{
    string computerWord = chooseWord();
    clearScreen();
    string guessedWord = string(computerWord.length(), '-');
    int wrongCount = 0;
    do{
        renderGame(guessedWord);
        printFigure(wrongCount);
        char guessWord = readGuessWord();
        if (check(computerWord, guessWord)){
            guessedWord = update(guessedWord, guessWord, computerWord);
        }
        else{
            wrongCount ++;
        }

    }while(wrongCount < maxWrongCount && guessedWord != computerWord);

    if (wrongCount == 7) {
            clearScreen();
            printFigure(7);
            cout << "The word is " << computerWord << endl << "Ohh!! You lose!! Lucky next game.." << endl;
    }
    if  (guessedWord == computerWord) cout << computerWord << " is true. Nice bro!!" << endl;

}

string getLowerCaseString (string& s)
{
    string res = s;
    transform(s.begin(), s.end(), res.begin(), ::tolower);
    return res;
}
string chooseWord()
{
    string word;
    cout << "Enter your word you want your friend guess: ";
    cin >> word;
    return word;
}
bool check(string computerWord, char guessWord)
{
    return (computerWord.find_first_of(guessWord) != string::npos);
}

string update(string guessedWord, char guessWord, string computerWord)
{
    for (int i = 0; i < guessedWord.length(); i++){
        if  (guessWord == computerWord[i]) guessedWord[i] = guessWord;
    }
    cout << guessedWord << endl;
    return guessedWord;
}


void clearScreen() {
    const int PATCH_LINES = 30;
	for (int i = 0; i < PATCH_LINES; i++) cout << endl;
}

void renderGame(string guessedWord)
{
    clearScreen();
    cout << guessedWord << endl;
}

char readGuessWord()
{
    char c;
    cout << "Enter your guess: ";
    cin >> c;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // xóa buffer
    return c;
}

void printFigure(int wrongCount)
{
    string Figure[] = {
    "   -------------    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |           |    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
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
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          /     \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        " -----   \n"
    };
    cout << Figure[wrongCount];
}


