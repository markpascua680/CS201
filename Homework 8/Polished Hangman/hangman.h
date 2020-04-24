/* hangman.h
   Jay-Mark Pascua
   CS 201
   04/23/2020
   Hangman header file
*/

#include <map>

#pragma once
#ifndef HANGMAN_H
#define HANGMAN_H


std::string answer = "computer"; // Hangman answer
std::map<char, char> blanks { // Displays blank spaces; will reveal letter if guessed correctly
    {'c', '_'},
    {'o', '_'},
    {'m', '_'},
    {'p', '_'},
    {'u', '_'},
    {'t', '_'},
    {'e', '_'},
    {'r', '_'}
};
int attempts = 10; // Attempts to guess

char guess(); // Player guesses a letter

void checkGuess(char& guess); // Check if letter guessed is correct/incorrect/used before

void correct(char& guess); // Reveals letter according to blank spaces

void incorrect(char& guess); // Tells player their guess is incorrect

void hasBeenUsed(char& guess); // Tells player their guess has been used before

bool gameOver(); // Stops game

#endif 
