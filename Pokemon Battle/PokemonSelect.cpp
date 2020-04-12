/* PokemonSelect.cpp
   Jay-Mark Pascua
   CS 201
   03/22/2020
   Chooses Pokemon for players
*/

#include "Pokemon.h"

Pokemon choosePoke() {
    while (true) { // Player chooses a pokemon
        if (GetKeyState('1') < 0) {
            Pokemon pPokemon = pSelect(1);
            cout << "\nYou chose " << pPokemon.name << '!' << endl;
            return pPokemon;
        }
        if (GetKeyState('2') < 0) {
            Pokemon pPokemon = pSelect(2);
            cout << "\nYou chose " << pPokemon.name << '!' << endl;
            return pPokemon;
        }
        if (GetKeyState('3') < 0) {
            Pokemon pPokemon = pSelect(3);
            cout << "\nYou chose " << pPokemon.name << '!' << endl;
            return pPokemon;
        }
        if (GetKeyState('4') < 0) {
            Pokemon pPokemon = pSelect(4);
            cout << "\nYou chose " << pPokemon.name << '!' << endl;
            return pPokemon;
        }
        if (GetKeyState('5') < 0) {
            Pokemon pPokemon = pSelect(5);
            cout << "\nYou chose " << pPokemon.name << '!' << endl;
            return pPokemon;
        }
    }
}


// Pokemon, type, moves, level, hp, atk, def, spAtk, spDef, speed, accuracy
Pokemon pSelect(int id)
{
    if (id == 1) // Can be extended to add more Pokemon
    {
        Pokemon Bulbasaur{ "Bulbasaur", "Grass", makeMoveSet(id), 12, 45, 49, 49, 65, 65, 45, 100 };
        return Bulbasaur;
    }
    else if (id == 2) {
        Pokemon Charmander{ "Charmander", "Fire", makeMoveSet(id), 14, 39, 52, 43, 60, 50, 65, 100 };
        return Charmander;
    }
    else if (id == 3) {
        Pokemon Squirtle{ "Squirtle", "Water", makeMoveSet(id), 16, 44, 48, 65, 50, 64, 43, 100 };
        return Squirtle;
    }
    else if (id == 4) {
        Pokemon Pikachu{ "Pikachu", "Electric", makeMoveSet(id), 13, 35, 55, 40, 50, 50, 90, 100 };
        return Pikachu;
    }
    else {
        Pokemon Bidoof{ "Bidoof", "Normal", makeMoveSet(id), 15, 49, 45, 40, 35, 40, 31, 100 };
        return Bidoof;
    }
    



}