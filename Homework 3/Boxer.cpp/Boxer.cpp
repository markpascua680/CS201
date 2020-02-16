/* Jay-Mark Pascua
   CS 201
   02/13/2020
   Takes user's string and int input and prints a box of asterisks with the string in the center
*/
#include <iostream>
#include <string>
#include <vector>
#include "Boxer.h"

string box(string word, int n)
{
    string ast = ""; // Asterisks
    string message = "";

    // BOX TOP
    if (n != 0)
    {
        ast += "****";
        for (int i = 0; i < word.size(); i++) // Prints asterisks length
        {
            ast += "*";
        }

        for (int i = 0; i < n; i++) // Prints asterisks width
        {
            ast += "\n" + ast;
        }
    }

    // BOX MID W/ MESSAGE






    return ast;
}