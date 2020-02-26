/* Bulls-And-Cows.cpp
   Jay-Mark Pascua
   CS 201
   02/25/2020
*/
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    string ans = "7420"; // Number answer
    string guess = ""; // User's guess

    cout << "!!!!!  BULLS AND COWS  !!!!!\nGuess the four digit number!" << endl;

    while (guess != ans) // Loops user's input so they can keep guessing
    {
        getline(cin, guess);
    }

    return 0;
}