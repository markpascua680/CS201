/* TokenizerTest.cpp
   Jay-Mark Pascua
   CS 201
   02/24/2020
   Takes in a string and divides it into tokens of smaller strings, derived from the original string
*/

#include "Tokenizer.h"

/////////////////////////////READLINE FUNCTION//////////////////////////////////
// Reads user's input
bool ReadLine(string& str)
{
        if (str == "") // Outputs false if string is blank 
        {
            return false;
        }
        return true;
}



//////////////////////////////STRING TO TOKENS WS FUNCTION/////////////////////////////////
// Reads strings separated by whitespace characters, returns number of tokens read from string 
unsigned StringToTokensWS(string& input, vector<string>& tokens) 
{
    istringstream word(input);

    while (word >> input) // Picks out each string separated by whitespace and puts into vector tokens
    {
        tokens.push_back(input);
    }
        tokens.push_back("");
    return tokens.size();
}



/////////////////////////ANALYZE TOKENS FUNCTION//////////////////////////////////////
// Determines type of token
void AnalyzeTokens(vector<string>& tokens)
{
    int flag = 0; // Determines the token
    for (auto i: tokens) // Goes through all elements of vector tokens
    {
        if (i == "") // TEST IF TOKEN = WHITESPACE
        {
            flag = 4;
        }
        
        for (int j = 0; j < i.size(); j++) // Goes through all letters of token; int j = element of string
        {
            if (flag != 0 && flag != 1) // Stops for loop if token is determined
            {
                break;
            }


            if (i.at(j) == '"' && i.at(i.size()-1) == '"') // TEST IF TOKEN = STRING LITERAL
            {
                flag = 2;
                break;
            }

            
            for (char c = 48; c <= 57; c++) // TEST IF TOKEN = INTEGER LITERAL; char c = numbers 0-9
            {
                if (i.at(j) == c)
                {
                    flag = 1;
                    break;
                }
                else if (i.at(j) != c) // TEST IF TOKEN = IDENTIFIER;
                {
                    flag = 3;
                }
            }
        }


        if (flag == 0)
        {
            cout << "[Unknown]\t";
        }

        if (flag == 1) // Token is integer literal
        {
            cout << "[Integer]\t";
        }

        
        if (flag == 2) // Token is string literal
        {
            cout << "[String]\t";
            cout << "\"\\\"" << i.substr(1, i.size()-2) << "\\\"\"" << endl;
        }


        if (flag == 3) // Token is identifier literal
        {
            cout << "[Identifier]\t";
        }

        if (flag == 4) // Token is whitespace literal
        {
            cout << "[Whitespace]\t";
        }

        if (flag != 2)
        {
            cout << "\"" << i << "\"" << endl;
        }

        flag = 0; // Resets to test next token
    }
}