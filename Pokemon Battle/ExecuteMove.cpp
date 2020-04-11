/* ExecuteMove.cpp
   Jay-Mark Pascua
   CS 201
   03/22/2020
   Executes an attack and manages turns
*/

#include "Pokemon.h"

void decideTurn(Pokemon pPokemon, Pokemon cPokemon) {
    if (pPokemon.speed > cPokemon.speed) {
        playerTurn();
    }
    else
        cpuTurn();
}

double damageCalculator() // Calculates damage of attacks
{
    // p = The attack's base power
    // a = Attacker's attack/special attack stat
    // d = Defender's defense/special defense stat
    //    double damage = (((0.4 / 5) * p * a / d) / 50) + 2;
    return 0.0;
}


void playerTurn() {

}

void cpuTurn() {

}
