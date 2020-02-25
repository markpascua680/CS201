/* Tokenizer.cpp
   Jay-Mark Pascua
   CS 201
   02/24/2020
   Takes in a string and divides it into tokens of smaller strings, derived from the original string
*/

#include "Tokenizer.h"

int main()
{
    vector<string> tokens;
    string str; // User's input

    cout << "Please type in some text. Enter \"End\", \"end\", or \"END\" when finished." << endl;

    while (true) // Loops user's input
    {
        getline(cin, str);
        if (str == "End" || str == "end" || str == "END") // Stops program if "End", "end", or "END" are inputted
        {
            StringToTokensWS(str, tokens);
            break;
        }
        
        if (ReadLine(str) == true) // Passes string to StringToTokensWS if it's not a blank
        {
            StringToTokensWS(str, tokens);
        }
    }

    tokens.pop_back(); // Deletes the excess whitespace at the end of the vector after user enters "End"

    for (int i = 0; i < tokens.size(); i++) // Prints token vector
    {
        cout << "HERE: " << tokens[i] << endl;
    }

    

    return 0;
}