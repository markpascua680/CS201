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

        if (guess.size() < 4) // Error check
        {
            cout << "Please enter four digits!" << endl;
        }

        if (guess.size() == 4)
        {
            Bulls(guess);
            Cows(guess);
        }
    }

    cout << "\nYou got four bulls!" << endl;

    return 0;
}


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

    if (bulls == 0)
    {
        cout << bulls << " bulls and ";
    }
    else if (bulls == 1)
    {
        cout << bulls << " bull and ";
    }
    else if (bulls > 1)
    {
        cout << bulls << " bulls and ";
    }
}



void Cows(string guess)
{
    
}