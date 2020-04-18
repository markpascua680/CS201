/* Caesar-Cypher.cpp
   Jay-Mark Pascua
   CS 201
   04/15/2020
   Encrypts the inputted string through Caesar Cypher
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;

std::string cypher(std::string message, int shift);

int main() {

    cout << "Enter a sentence to cypher (blank line to end): ";

    std::string message;
    std::getline(std::cin, message); // User input

    std::string::iterator it;

    std::string errors = "0123456789"; // Characters that aren't allowed
    it = std::find_first_of(message.begin(), message.end(), errors.begin(), errors.end()); // Checks if input has a symbol/number

    while (it != message.end()) { // Ensures input is letters only
        cout << "Please don't include numbers or symbols in the message." << endl;;
        std::getline(std::cin, message);
        it = std::find_first_of(message.begin(), message.end(), errors.begin(), errors.end()); // Checks again
    }

    std::string blank = " ";
    if (message.empty() || message == blank) { // Ends program if message is empty or blank space
        cout << "Program closed" << endl;
        return 0;
    }

    int shift;
    cout << "Enter an integer to use as the shift: ";
    std::cin >> shift;

    while (!std::cin) {
        cout << "Please enter a valid number: " << endl;
        std::cin >> shift;
    }

    cout << "Result: " << cypher(message, shift);

    return 0;
}

std::string cypher(std::string message, int shift) { // Cyphers the user's message
    std::string letters = "abcdefghijklmnopqrstuvwxyz"; // Stores letters to refer to when shifting
    std::string lettersCapital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char blank = ' '; // Will help test for spaces
    size_t index; // Index of a letter in string letters

    for (size_t i = 0; i < message.size(); i++) { // Goes through all letters of the message
        index = letters.find(message[i]); // Takes a letter from message and finds it in letters; returns its index

        if (message[i] == blank)
            continue;

        if (index == std::string::npos) { // If message[i] isn't found in string letters
            index = lettersCapital.find(message[i]); // Try to find it in string lettersCapital

            if (index + shift > lettersCapital.size() - 1) { // If shift > string range, returns back to start of string
                index = (index + shift) - lettersCapital.size();
                message[i] = lettersCapital[index];
                continue;

            }else if (index == std::string::npos) { // If the character isn't found in string lettersCapital, continue
                continue;
            }

            else { // Else if it is found, change the letter in message
                message[i] = lettersCapital[index + shift];
                continue;
            }

            if (index == std::string::npos) {
                continue;
            }
        }

        if (index + shift > letters.size() - 1) { // If shift > string range, returns back to start of string
            index = (index + shift) - letters.size();
            message[i] = letters[index];
            continue;
        }

        else {
            message[i] = letters[index + shift];
        }
    }
    return message;
}