/* BattleLoop.cpp
   Jay-Mark Pascua
   CS 201
   03/22/2020
   Executes attacks and manages turns
*/

#include "Pokemon.h"
void playerTurn();
void cpuTurn();
void defensiveMove(Pokemon& attacker, Pokemon& defender, int move);
void offensiveMove(Pokemon& attacker, Pokemon& defender, int move);

Pokemon tempPlayerPokemon; // Temporary copy of pokemon stats to allow modification only in battle
Pokemon tempCpuPokemon;

void getStats(Pokemon pokemon) {
    cout << pokemon.name << endl;
    cout << pokemon.atk << endl;
    cout << pokemon.def << endl;
    cout << pokemon.spAtk << endl;
    cout << pokemon.spDef << endl;
    cout << pokemon.accuracy << endl;
}

void decideTurn(Pokemon& pPokemon, Pokemon& cPokemon) { // Decides who goes first
    tempPlayerPokemon = pPokemon; // Assigns temporary copy of pokemon stats
    tempCpuPokemon = cPokemon;
    if (pPokemon.speed > cPokemon.speed) {
        playerTurn();
    }
    else {
        cpuTurn();
    }
}

void determineMove(Pokemon& attacker, Pokemon& defender, int move) { // Determines if move is defensive or offensive
    if (attacker.attack[move].getPower() == 0) { // Test if move is defensive, otherwise it's offensive
        defensiveMove(attacker, defender, move);
    }
    else
        offensiveMove(attacker, defender, move);
}

void defensiveMove(Pokemon& attacker, Pokemon& defender, int move) { // Applies the status to pokemon
    string status = attacker.attack[move].getName();
    attacker.attack[move].pp -= 1;

    cout << attacker.name << " used " << attacker.attack[move].getName() << '!' << endl;

    if (status == "Growth") { // Raises user's attack and special attack by 10%
        attacker.atk += attacker.atk * 0.1;
        attacker.spAtk += attacker.spAtk * 0.1;
        cout << "Its attack and special attack rose!" << endl;
    }
    else if (status == "Defense Curl") { // Raises user's defense by 10%
        attacker.def += attacker.def * 0.1;
        cout << "Its defense rose!" << endl;
    }
    else if (status == "Smokescreen") { // Lowers target's accuracy by 10%
        defender.accuracy -= defender.accuracy * 0.1;
        cout << defender.name << "'s accuracy fell!" << endl;
    }
    else if (status == "Tail Whip") { // Lowers target's defense by 10%
        defender.def -= defender.def * 0.1;
        cout << defender.name << "'s defense fell!" << endl;
    }
    else if (status == "Play Nice") { // Lowers target's attack by 10%
        defender.atk -= defender.atk * 0.1;
        cout << defender.name << "'s attack fell!" << endl;
    }
}

void offensiveMove(Pokemon& attacker, Pokemon& defender, int move) {
    attacker.attack[move].getPower();
    cout << attacker.name << " used " << attacker.attack[move].getName() << '!' << endl;
    attacker.attack[move].pp -= 1;
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

random_device r;
uniform_int_distribution<int> random(0, 3); // Opponent uses a random ability
void cpuTurn() { // Computer's turn to attack
    switch (random(r))
    {
    case 0: cout << "Opponent's "; 
        determineMove(tempCpuPokemon, tempPlayerPokemon, 0); // What kind of move is used is determined and then passed to 
        break;                                               // defensiveMove or offensiveMove functions
    case 1: cout << "Opponent's "; 
        determineMove(tempCpuPokemon, tempPlayerPokemon, 1);
        break;
    case 2: cout << "Opponent's "; 
        determineMove(tempCpuPokemon, tempPlayerPokemon, 2);
        break;
    case 3: cout << "Opponent's "; 
        determineMove(tempCpuPokemon, tempPlayerPokemon, 3);
        break;
    }
    playerTurn();
}
