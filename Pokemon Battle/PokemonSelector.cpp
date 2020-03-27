/* PokemonSelector.cpp
   Jay-Mark Pascua
   CS 201
   03/22/2020
   Holds Pokemon and their stats
*/

#include "Pokemon.h"

double hp;
double atk;
double def;
double spAtk;
double spDef;
double speed;

// Pokemon                hp, atk, def, spAtk, spDef, speed
vector<double> bulbStats{ 45, 49, 49, 65, 65, 45 }; // Bulbasaur ID #1
vector<double> charStats{ 39, 52, 43, 60, 50, 65 }; // Charmander ID #2
vector<double> squiStats{ 44, 48, 65, 50, 64, 43 }; // Squirtle ID #3
vector<double> pikaStats{ 35, 55, 40, 50, 50, 90 }; // Pikachu ID #4
vector<double> bidoStats{ 59, 45, 40, 35, 40, 31 }; // Bidoof ID #5

struct Stats
{

};

vector<double> pSelect(int id)
{
    switch (id)
    {
    case 1:
        cout << " Bulbasaur!" << endl;
        return bulbStats;
    case 2:
        cout << " Charmander!" << endl;
        return charStats;
    case 3:
        cout << " Squirtle!" << endl;
        return squiStats;
    case 4:
        cout << " Pikachu!" << endl;
        return pikaStats;
    case 5:
        cout << " Bidoof!" << endl;
        return bidoStats;
    }
    



}