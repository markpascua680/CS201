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

int selectOption() {
    while (true) { // Player chooses a pokemon
        if (GetKeyState('1') & 0x8000) {
            return 1;
        }
        if (GetKeyState('2') & 0x8000) {
            return 2;
        }
        if (GetKeyState('3') & 0x8000) {
            return 3;
        }
        if (GetKeyState('4') & 0x8000) {
            return 4;
        }
        if (GetKeyState('5') & 0x8000) {
            return 5;
        }
    }
}

void displayOptions() { // Displays player's options when it's their turn
    cout << "[1] FIGHT\n[2] STATS" << endl;
}

void displayAttacks(Pokemon& p) {
    cout << endl;
    for (int i = 0; i < 4;i++) {
        cout << '[' << i << "] " << setw(20) << left << p.attack[i].getName() << "PP: " << p.attack[i].pp << endl;
    }
}