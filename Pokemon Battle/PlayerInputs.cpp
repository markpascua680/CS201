/* PlayerInputs.cpp
   Jay-Mark Pascua
   CS 201
   04/10/2020
   Handles player inputs
*/

#include "Pokemon.h"

Pokemon choosePoke() {
    while (true) { // Player chooses a pokemon
        if (GetKeyState('1') & 0x8000) {
            Pokemon pPokemon = pSelect(1);
            cout << "\nYou chose " << pPokemon.name << '!' << endl;
            return pPokemon;
        }
        if (GetKeyState('2') & 0x8000) {
            Pokemon pPokemon = pSelect(2);
            cout << "\nYou chose " << pPokemon.name << '!' << endl;
            return pPokemon;
        }
        if (GetKeyState('3') & 0x8000) {
            Pokemon pPokemon = pSelect(3);
            cout << "\nYou chose " << pPokemon.name << '!' << endl;
            return pPokemon;
        }
        if (GetKeyState('4') & 0x8000) {
            Pokemon pPokemon = pSelect(4);
            cout << "\nYou chose " << pPokemon.name << '!' << endl;
            return pPokemon;
        }
        if (GetKeyState('5') & 0x8000) {
            Pokemon pPokemon = pSelect(5);
            cout << "\nYou chose " << pPokemon.name << '!' << endl;
            return pPokemon;
        }
    }
}