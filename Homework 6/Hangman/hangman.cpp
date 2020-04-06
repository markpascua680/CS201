/* hangman.cpp
   Jay-Mark Pascua
   CS 201
   04/04/2020
   Hangman game
*/

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool isCorrect(string guess) // Checks if guessed letter is correct
{

    return false;
}

void main()
{
    
    string guess; // User guesses a letter
    map<int, string> usedLetters; // Stores used letters
    
    int i = 1; // Number of iterations for while loop
    int flag = 0; // 0 = lose, 1 = win

    while (i != 10 && flag == 0) // User has 10 chances to guess
    {
        cout << "Guess a letter: ";
        cin >> guess;

        if (guess.length() == 1) { // Test if input is one letter
            isCorrect(guess);
            cout << "Guess: " << guess << endl;
        }
        else if (guess == "moist") { // Ends loop if user guesses the answer

        }
        
    }

}