/* Tokenizer.cpp
   Jay-Mark Pascua
   CS 201
   02/24/2020
   Takes in a string and divides it into tokens of smaller strings, derived from the original string
*/

#include "Tokenizer.h"

int main()
{

    string str; // User's input

    cout << "Please type in some text. Enter \"End\", \"end\", or \"END\" when finished." << endl;

    while (true) // Loops user's input
    {
        getline(cin, str);
        if (str == "End" || str == "end" || str == "END") // Stops program if "End", "end", or "END" are inputted
        {
            break;
        }
        ReadLine(str);
    }

    

    return 0;
}