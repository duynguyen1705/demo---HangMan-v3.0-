#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <fstream>
#include <algorithm>
#include<thread>
#include<chrono>

using namespace std;

const int maxWrongCount = 7;
void printFigure(int wrongCount);
string chooseWord(string topic);
bool check(string computerWord, char guessWord);
string update(string guessedWord, char guessWord, string computerWord);
void printResult();
void renderGame(string guessedWord);
char readGuessWord();
string getTopic();

int main()
{
    srand(time(0));
    string topic = getTopic();
    string computerWord = chooseWord(topic);
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
	    printFigure(7);
	    cout << computerWord << "is the true word!!";
    }
    if  (guessedWord == computerWord) cout << computerWord << " is true. Nice bro!!" << endl;
    printResult();

}

string getLowerCaseString (string& s)
{
    string res = s;
    transform(s.begin(), s.end(), res.begin(), ::tolower);
    return res;
}
string chooseWord(string topic)
{
    vector<string> wordList;
    string nfile = "data/" + topic + ".txt";
    ifstream file(nfile);
    if(file.is_open()){
        string word;
        while(file >> word){
            wordList.push_back(word);
        }
        file.close();
    }
    if (wordList.size() > 0){
        int randomIndex = rand() % wordList.size();
        return getLowerCaseString(wordList[randomIndex]);
    }else return "";
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

void printResult()
{
    cout << "Game Over!";
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
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // x�a buffer
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

string getTopic()
{
    string topic;

    do{
        cout << "Enter your topic you want(flower, animal, sport): ";
        cin >> topic;
    }while(topic != "flower" && topic != "animal" && topic != "sport");

    return topic;
}

