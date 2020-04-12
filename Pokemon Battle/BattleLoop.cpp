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
int damageCalculator(int p, int a, int d);
double damageMultiplier(Pokemon& a, Pokemon& d, int move);

Pokemon tempPlayerPokemon; // Temporary copy of pokemon stats to allow modification only in battle
Pokemon tempCpuPokemon;



void getStats(Pokemon pokemon) {
    cout << pokemon.hp;
    /*
    cout << pokemon.name << endl;
    cout << pokemon.atk << endl;
    cout << pokemon.def << endl;
    cout << pokemon.spAtk << endl;
    cout << pokemon.spDef << endl;
    cout << pokemon.accuracy << endl;*/
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
        attacker.atk += attacker.atk * (int)0.1;
        attacker.spAtk += attacker.spAtk * (int)0.1;
        cout << "Its attack and special attack rose!" << endl;
    }
    else if (status == "Defense Curl") { // Raises user's defense by 10%
        attacker.def += attacker.def * (int)0.1;
        cout << "Its defense rose!" << endl;
    }
    else if (status == "Smokescreen") { // Lowers target's accuracy by 10%
        defender.accuracy -= defender.accuracy * (int)0.1;
        cout << defender.name << "'s accuracy fell!" << endl;
    }
    else if (status == "Tail Whip") { // Lowers target's defense by 10%
        defender.def -= defender.def * (int)0.1;
        cout << defender.name << "'s defense fell!" << endl;
    }
    else if (status == "Play Nice") { // Lowers target's attack by 10%
        defender.atk -= defender.atk * (int)0.1;
        cout << defender.name << "'s attack fell!" << endl;
    }
}



void offensiveMove(Pokemon& attacker, Pokemon& defender, int move) {
    int power = attacker.attack[move].getPower();
    int atk;
    int def;
    if (attacker.attack[move].getCategory() == "Physical") { // If attack is physical, use attacker's atk stat and defender's def stat
        atk = attacker.atk;
        def = defender.def;
    }
    else {
        atk = attacker.spAtk;
        def = defender.spDef;
    }
    attacker.attack[move].pp -= 1;
    cout << attacker.name << " used " << attacker.attack[move].getName() << '!' << endl;
    int damage = (int)round(damageCalculator(power, atk, def) * damageMultiplier(attacker, defender, move));
}



double damageMultiplier(Pokemon& a, Pokemon& d, int move) { // Increases/decreases damage total based on the attack's type and defender's type
    string attackType = a.attack[move].getType();
    string defenderType = d.type;
    if (attackType == "Normal") { // Normal attacks against other types
        return 1;
    }
    else if (attackType == "Grass") { // Grass attacks against other types
        if (defenderType == "Water") {
            cout << "It's super effective!" << endl;
            return 2;
        }
        else if (defenderType == "Grass" || defenderType == "Fire") { 
            cout << "It's not very effective..." << endl;
            return 0.5;
        }
        else
            return 1;
    }
    else if (attackType == "Fire") { // Fire attacks against other types
        if (defenderType == "Grass") {
            cout << "It's super effective!" << endl;
            return 2;
        }
        else if (defenderType == "Fire") {
            cout << "It's not very effective..." << endl;
            return 0.5;
        }
        else
            return 1;
    }
    else if (attackType == "Water") { // Water attacks against other types
        if (defenderType == "Fire") {
            cout << "It's super effective!" << endl;
            return 2;
        }
        else if (defenderType == "Water" || defenderType == "Grass") {
            cout << "It's not very effective..." << endl;
            return 0.5;
        }
        else
            return 1;
    }
    else if (attackType == "Electric") {
        if (defenderType == "Water") {
            cout << "It's super effective!" << endl;
            return 2;
        }
        else if (defenderType == "Electric" || defenderType == "Grass") {
            cout << "It's not very effective..." << endl;
            return 0.5;
        }
        else
            return 1;
    }
    else if (attackType == "Rock") {
        if (defenderType == "Fire") {
            cout << "It's super effective!" << endl;
            return 2;
        }
        else
            return 1;
    }
}



int damageCalculator(int p, int a, int d) // Calculates damage of attacks
{
    double damage = a / d; // a = Attacker's attack/special attack stat
    damage *= 2.08 * p;    // d = Defender's defense/special defense stat
    damage /= 50;          // p = The attack's base power
    damage += 2;
    damage = round(damage);
    return (int)damage;
}



void playerTurn() { // User can attack or check stats of their own pokemon
    bool go = true;
    while(go) {
        cout << "What will you do?" << endl;
        displayOptions();
        if (selectOption() == 0) {
            displayAttacks(tempPlayerPokemon);
            int option = selectOption();
            if (option != 4) {
                determineMove(tempPlayerPokemon, tempCpuPokemon, option);
                go = false;
            }
            else if(option == 4)
                continue;
        }
        else if (selectOption() == 1) {
            getStats(tempPlayerPokemon);
        }
        break;
    }
    cpuTurn();
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
