/* hangman.cpp
   Jay-Mark Pascua
   CS 201
   04/04/2020
   Hangman game
*/

#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool isCorrect(vector<string> answer, string guess) // Checks if guessed letter is correct
{
    if (find(answer.begin(), answer.end(), guess) != answer.end()) { // Check if guessed letter is in answer
        return true;
    }
    return false;
}

void printBlanks(vector<string>& blanks) { // Prints underscores of unrevealed letters
    for_each(blanks.begin(), blanks.end(), [](string a) {cout << a;});
}

void revealLetter(vector<string>& answer, vector<string>& blanks, string guess) {
    vector<string>::iterator it = find(answer.begin(), answer.end(), guess);
    blanks[it-answer.begin()] = guess;
}

bool allLettersFound(vector<string>& answer, vector<string>& blanks) {
    if (answer == blanks) {
        return true;
    }
    return false;
}

bool alreadyGuessed(map<int, string>& usedGuesses, string guess) {

}

void main()
{
    vector<string> answer{ "m", "o", "i", "s", "t" };
    vector<string> blanks{ "_ ", "_ ", "_ ", "_ ", "_ " };
    string guess; // User guesses a letter
    map<int, string> usedGuesses; // Stores used letters
    
    int attempts = 10; // User's chances of guessing
    int flag = 0; // 0 = lose, 1 = win

    while (attempts != 0 && flag == 0) // User has 10 chances to guess
    {
        cout << "~~~~~~~~~~ HANGMAN ~~~~~~~~~~" << endl;
        cout << "Attempts Remaining: " << attempts << endl;
        printBlanks(blanks); // Prints the underscores of unrevealed letters
        cout << "\nGuess a letter or the answer: ";
        cin >> guess;
        system("CLS");

        /*if (alreadyGuessed(usedGuesses, guess)) {
            cout << "You've already guessed that letter!";
            continue;
        }*/

        if (guess.length() == 1) { // Test if input is one letter
            if (isCorrect(answer, guess)) {
                cout << guess << " is correct!\n" << endl; // Correct if guessed right
                usedGuesses[attempts] = guess;
                attempts--;
                revealLetter(answer, blanks, guess);
            }
            else {
                cout << guess << " is incorrect!\n" << endl; // Incorrect if guessed wrong
                usedGuesses[attempts] = guess;
                attempts--;
            }
        }
        else if (guess == "moist") { // Ends loop if user guesses the answer
            cout << "You got it!\nThe answer is moist!" << endl;
            flag = 1;
        }
        else {
            cout << guess << " is incorrect!\n" << endl; // Incorrect if gussed wrong answer
            usedGuesses[attempts] = guess;
            attempts--;
        }
        if (allLettersFound(answer, blanks)) { // Checks if all letters of the answer have been found
            cout << "You got it!\nThe answer is moist!" << endl;
            flag = 1;
        }
        
    }
    if (attempts == 0) // User ran out of attempts message
        cout << "You ran out of attempts! Try again!";

}