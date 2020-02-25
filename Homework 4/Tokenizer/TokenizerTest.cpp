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

}