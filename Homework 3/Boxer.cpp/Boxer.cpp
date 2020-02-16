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
    string layers; // Helps print width of asterisks
    string message = ""; // Middle of the box

    string wid = ""; // Marks width of middle of box
    for (int i = 0; i < n; i++) // Marks width of middle of box
    {
        wid += "*";
    }

    /* BOX TOP + BOTTOM
            length
       ****************
       **************** width
       ****************
    */
    if (n != 0)
    {
        ast = "**";
            for (int i = 0; i < word.size(); i++) // Prints asterisks length
            {
                ast += "*";
            }
            ast = wid + ast + wid;
        if (n > 1)
        {
            for (int i = 0; i < n; i++) // Prints asterisks width
            {
                    layers += ast;

                    if (i < n - 1) // Prevents new lines after asterisks block
                        layers += "\n";
            }
            ast = layers;
        }

        
    }

    /* BOX MID W/ MESSAGE
       ***           *** <- SECTION 1
       *** (message) *** <- SECTION 2
       ***           *** <- SECTION 3
    */
    

    // SECTION 1
    message += wid + " ";
    for (int i = 0; i < word.size(); i++) // Prints space line above the message
    {
        message += " ";
    }
    message += " " + wid;


    // SECTION 2
    message += "\n" + wid + " " + word + " " + wid + "\n"; // Prints line with message


    // SECTION 3
    message += wid + " ";
    for (int i = 0; i < word.size(); i++) // Prints space line below the message
    {
        message += " ";
    }
    message += " " + wid;


    return ast + "\n" + message + "\n" + ast;
}