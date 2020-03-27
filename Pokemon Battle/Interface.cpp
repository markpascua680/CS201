/* Interface.cpp
   Jay-Mark Pascua
   CS 201
   03/22/2020
   Main outputs seen by user; user interface
*/

#include "Pokemon.h"

int main()
{
    srand((unsigned)time(0));

    Pokemon pPokemon = pSelect((rand() % 5) + 1); // Player's Pokemon
    cout << "You got " << pPokemon.name;

    Pokemon cPokemon =  pSelect((rand() % 5) + 1); // Opponent's Pokemon
    cout << "\nYour opponent got " << cPokemon.name;
    cout << endl;





    return 0;
}

