/* Bulls-And-Cows.cpp
   Jay-Mark Pascua
   CS 201
   02/25/2020
   User guesses a four digit number
*/
#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::istringstream;

void Bulls(string guess);
void Cows(string guess);

string ans = "7420"; // Number answer
string guess = ""; // User's guess

int main()
{
    cout << "!!!!!  BULLS AND COWS  !!!!!\nGuess the four digit number!" << endl;

    while (guess != ans) // Loops user's input so they can keep guessing
    {
        getline(cin, guess);

        int num;
        istringstream error(guess); // Ensures inputs are digits
        error >> num;
        if (guess.size() < 4 || guess.size() > 4 || !error) // Error check
        {
            cout << "Please enter four digits!" << endl;
        }

        if (guess.size() == 4 && error)
        {
            Bulls(guess);
            Cows(guess);
        }
    }

    cout << "\nYou got four bulls!" << endl;

    return 0;
}

///////////////BULLS FUNCTION///////////////
void Bulls(string guess) // Searches for correct numbers in correct position
{
    int bulls = 0;
    for (int i = 0; i < 4; i++) // int i = elements of answer number and guessed number
    {
        if (ans.at(i) == guess.at(i))
        {
            bulls++;
        }
    }

    if (bulls == 0 || bulls > 1) // Outputs number of correct numbers in the correct position
    {
        cout << bulls << " bulls and ";
    }
    else if (bulls == 1)
    {
        cout << bulls << " bull and ";
    }
}


///////////////COWS FUNCTION///////////////
void Cows(string guess) // Searches for correct numbers in wrong position
{
    int cows = 0;

    if (guess.at(0) == '4' || guess.at(0) == '2' || guess.at(0) == '0')
    {
        cows++;
    }

    if (guess.at(1) == '7' || guess.at(1) == '2' || guess.at(1) == '0')
    {
        cows++;
    }

    if (guess.at(2) == '7' || guess.at(2) == '4' || guess.at(2) == '0')
    {
        cows++;
    }

    if (guess.at(3) == '7' || guess.at(3) == '4' || guess.at(3) == '2')
    {
        cows++;
    }


    if (cows == 0 || cows > 1) // Outputs number of correct numbers in the wrong position
    {
        cout << cows << " cows" << endl;
    }
    else if (cows == 1)
    {
        cout << cows << " cow" << endl;
    }
}