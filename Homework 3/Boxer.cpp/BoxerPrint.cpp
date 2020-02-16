/* Jay-Mark Pascua
   CS 201
   02/13/2020
   Takes user's string and int input and prints a box of asterisks with the string in the center
*/
#include <iostream>
#include <string>
#include <vector>
#include "Boxer.h"

int main()
{
    string word; // User's message input
    int n;       // User's int input

    while (word != "STOP")
    {
        cout << "Enter a Message (or STOP to cancel): ";
        cin >> word;
        if (word == "STOP") // Stop program
            break;

        cout << "\nEnter a positive number: ";
        cin >> n;

        cout << box(word, n) << endl;

    }


    return 0;
}