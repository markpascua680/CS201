/* PokemonSelect.cpp
   Jay-Mark Pascua
   CS 201
   03/22/2020
   Chooses Pokemon for players
*/

#include "Pokemon.h"

// Pokemon, type, moves, level, hp, atk, def, spAtk, spDef, speed
Pokemon pSelect(int id)
{
    if (id == 1) // Can be extended to add more Pokemon
    {
        Pokemon Bulbasaur{ "Bulbasaur", "Grass", bulbMoves, 12, 45, 49, 49, 65, 65, 45 };
        return Bulbasaur;
    }
    else if (id == 2) {
        Pokemon Charmander{ "Charmander!", "Fire", charMoves, 14, 39, 52, 43, 60, 50, 65 };
        return Charmander;
    }
    else if (id == 3) {
        Pokemon Squirtle{ "Squirtle!", "Water", squiMoves, 16, 44, 48, 65, 50, 64, 43 };
        return Squirtle;
    }
    else if (id == 4) {
        Pokemon Pikachu{ "Pikachu!", "Electric", pikaMoves, 13, 35, 55, 40, 50, 50, 90 };
        return Pikachu;
    }
    else {
        Pokemon Bidoof{ "Bidoof!", "Normal", bidoMoves, 15, 59, 45, 40, 35, 40, 31 };
        return Bidoof;
    }
    



}