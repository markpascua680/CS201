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

    cout << "You got";
    vector<double> pPokemon = pSelect((rand() % 5) + 1); // Player's Pokemon

    cout << "\nYour opponent got";
    vector<double> cpuPokemon = pSelect((rand() % 5) + 1); // Opponent's Pokemon
    cout << endl;
    



    return 0;
}

