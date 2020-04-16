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

int main() {

    cout << "Enter a sentence to cypher (blank line to end): ";

    std::string message;
    std::getline(std::cin, message); // User input

    std::string::iterator it;

    std::string errors = "0123456789~!@#$%^&*()_+{}|:<>?`-=[]\\;\',./"; // Characters that aren't allowed
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

    cypher(message, shift);

    return 0;
}

std::string cypher(std::string message, int shift) {

}