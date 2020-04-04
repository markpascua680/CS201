/* Interface.cpp
   Jay-Mark Pascua
   CS 201
   03/22/2020
   Main outputs seen by user; user interface
*/

#include "Pokemon.h"

int main()
{
    cout << "\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\t\t\t\t\t   P O K E M O N" << endl;
    cout << "\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~" << endl;

    srand((unsigned)time(0)); // Generates random number

    Pokemon pPokemon = pSelect((rand() % 5) + 1); // Player's Pokemon
    cout << "You got " << pPokemon.name << endl;

    Pokemon cPokemon =  pSelect((rand() % 5) + 1); // Opponent's Pokemon
    cout << "\nYour opponent got " << cPokemon.name;
    cout << "\n\nThe battle will commence\n" << endl;
    system("PAUSE");
    system("CLS");

    /*for ( auto it = pPokemon.moves.begin(); it != pPokemon.moves.end(); it++)
    {
    }*/




    return 0;
}

