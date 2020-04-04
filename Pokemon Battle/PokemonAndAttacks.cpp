/* PokemonAndAttacks.cpp
   Jay-Mark Pascua
   CS 201
   03/22/2020
   Chooses Pokemon for players
*/

#include "Pokemon.h"

map<string, Attack> bulbMoves{ // Bulbasaur's moves
    {"Tackle", {"Normal", "Physical", 40, 100, 35} }, 
    {"Growth", {"Normal", "Status", 0, 100, 40} },      // Raises atk and spAtk by 10%
    {"Vine Whip", {"Grass", "Physical", 45, 100, 25} },
    {"Razor Leaf", {"Grass", "Physical", 55, 95, 25} }
};

map<string, Attack> charMoves{ // Charmander's moves
    {"Scratch", {"Normal", "Physical", 40, 100, 35} },
    {"Ember", {"Fire", "Special", 40, 100, 25} },       
    {"Smokescreen", {"Normal", "Status", 0, 100, 20} }, // Lowers target's accuracy by 10%
    {"Fire Fang", {"Fire", "Physical", 65, 95, 15} }
};

map<string, Attack> squiMoves{ // Squirtle's moves
    {"Tackle", {"Normal", "Physical", 40, 100, 35} },
    {"Tail Whip", {"Normal", "Status", 0, 100, 30} },   // Lowers target's defense by 10%
    {"Water Gun", {"Water", "Special", 40, 100, 25} },
    {"Water Pulse", {"Water", "Special", 60, 100, 20} }
};

map<string, Attack> pikaMoves{ // Pikachu's moves
    {"Quick Attack", {"Normal", "Physical", 40, 100, 30} },
    {"Play Nice", {"Normal", "Status", 0, 100, 20} },   // Lowers target's Attack by 10%
    {"Thunder Shock", {"Electric", "Special", 40, 100, 30} },
    {"Electro ball", {"Electric", "Physical", 65, 100, 20} }
};

map<string, Attack> bidoMoves{ // Bidoof's moves
    {"Defense Curl", {"Normal", "Status", 0, 100, 40} },     // Raises user's defense by 10%
    {"Growl", {"Normal", "Status", 0, 100, 40} },
    {"Tackle", {"Normal", "Physical", 40, 100, 35} },
    {"Rollout", {"Rock", "Physical", 30, 90, 20} } 
};


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