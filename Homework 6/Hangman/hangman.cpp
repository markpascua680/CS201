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



void main()
{
    string answer = "moist"; // Hangman solution
    string guess; // User guesses a letter
    map<char, string> usedLetters;

    
    

    for (int i = 1; i <= 10; i++)
    {
        cin >> guess;

        if (guess.length() == 1) { // Test if input is one letter
            cout << "Guess: " << guess << endl;
        }
        else if (guess == "moist") { // Test if user guesses the answer

        }
        
    }

}