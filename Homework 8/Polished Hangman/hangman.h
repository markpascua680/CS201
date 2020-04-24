/* hangman.h
   Jay-Mark Pascua
   CS 201
   04/23/2020
   Hangman header file
*/

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <Windows.h>

#pragma once
#ifndef HANGMAN_H
#define HANGMAN_H


std::string answer = "computer"; // Hangman answer
std::string blanks = "________"; // Holds the letters that are revealed/unrevealed
std::vector<char> usedLetters = {};
int attempts = 10;


void incorrect(char& guess) { // Tells player their guess is incorrect
    std::cout << "Incorrect!" << std::endl;
}


void correct(char& guess) { // Reveals letter according to blank spaces
    int found = answer.find(guess);
    if (found != -1) {
        blanks[found] = guess;
        std::cout << "Correct!" << std::endl;
    }
    else {
        incorrect(guess);
    }
}


bool hasBeenUsed(char& guess) { // Tells player their guess has been used before
    for (auto x : usedLetters) {
        if (guess == x) {
            std::cout << "That letter has already been guessed!" << std::endl;
            usedLetters.pop_back(); // Removes repeated letter
            return true;
        }
    }
    return false;
}


bool gameOver() { // Stops game
    if (answer == blanks) {
        std::cout << "You guessed it! The answer is " << answer << std::endl;
        return true;
    }
    else if (attempts == 0) {
        std::cout << "You ran out of attempts! The answer was " << answer << std::endl;
        return true;
    }
    return false;
}


std::string printBlanks() { // Prints the letters that are revealed/unrevealed

    return blanks;
}

#endif 
