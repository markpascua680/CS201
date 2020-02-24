/* Tokenizer.h
   Jay-Mark Pascua
   CS 201
   02/24/2020
   Takes in a string and divides it into tokens of smaller strings, derived from the original string
*/
#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::istringstream;
using std::string;
using std::vector;

bool ReadLine(string& str);
unsigned StringToTokensWS(string& input, vector<string>& tokens);
void AnalyzeTokens(vector<string>& tokens);

#endif