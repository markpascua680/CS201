/* hangman_main.cpp
   Jay-Mark Pascua
   CS 201
   04/23/2020
   Simple Hangman game
*/

#include <iostream>
#include "hangman.h"

int main() {

    std::cout << "%%%%%%%%%%%%%%%" << std::endl;
    std::cout << "%%  HANGMAN  %%" << std::endl;
    std::cout << "%%%%%%%%%%%%%%%\n" << std::endl;

    while (!gameOver()) { // Continues to loop if there are attempts left

        std::cout << printBlanks() << std::endl;
        std::cout << "\n\nAttempts Remaining: " << attempts << std::endl;
        std::cout << "Guess a letter: ";

        char letter;
        std::cin >> letter; // User guesses a letter

        std::cout << '\n';

        if (hasBeenUsed(letter)) { // Checks if letter has already been guessed before
            continue;
        }

        usedLetters.push_back(letter); // Adds letter to used vector

        correct(letter);

        if (gameOver())
            break;
        attempts--;
        
    }

    return 0;
}