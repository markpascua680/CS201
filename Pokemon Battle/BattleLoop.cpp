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
void lowerHealth(Pokemon& defender, int damage);
bool isFainted(Pokemon& player, Pokemon& opponent);
void endBattle(Pokemon& player, Pokemon& opponent);

Pokemon pPokemon; // Original copies of pokemon
Pokemon cPokemon;
Pokemon tempPlayerPokemon; // Temporary copy of pokemon stats to allow modification only in battle
Pokemon tempCpuPokemon;



void getStats(Pokemon pokemon) {
    cout << string(15, '\n');
    cout << setw(5) << left << "ATK: " << setw(5) << left << pokemon.atk << endl;
    cout << setw(5) << left << "DEF: " << setw(5) << left << pokemon.def << endl;
    cout << setw(5) << left << "SP.ATK: " << setw(5) << left << pokemon.spAtk << endl;
    cout << setw(5) << left << "SP.DEF: " << setw(5) << left << pokemon.spDef << endl;
    cout << setw(5) << left << "ACC: " << setw(5) << left << pokemon.accuracy << endl;
    Sleep(3000);
}



void decideTurn(Pokemon& pPokemon1, Pokemon& cPokemon1) { // Decides who goes first
    pPokemon = pPokemon1; // Allows usage of original stats to be called
    cPokemon = cPokemon1;
    tempPlayerPokemon = pPokemon1; // Assigns temporary copy of pokemon stats
    tempCpuPokemon = cPokemon1;
    if (pPokemon1.speed > cPokemon1.speed) {
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
        attacker.atk += attacker.atk * (int)0.2;
        attacker.spAtk += attacker.spAtk * (int)0.2;
        cout << "Its attack and special attack rose!" << endl;
    }
    else if (status == "Defense Curl") { // Raises user's defense by 10%
        attacker.def += attacker.def * (int)0.2;
        cout << "Its defense rose!" << endl;
    }
    else if (status == "Smokescreen") { // Lowers target's accuracy by 10%
        defender.accuracy -= defender.accuracy * (int)0.1;
        cout << defender.name << "'s accuracy fell!" << endl;
    }
    else if (status == "Tail Whip") { // Lowers target's defense by 10%
        defender.def -= defender.def * (int)0.2;
        cout << defender.name << "'s defense fell!" << endl;
    }
    else if (status == "Play Nice") { // Lowers target's attack by 10%
        defender.atk -= defender.atk * (int)0.2;
        cout << defender.name << "'s attack fell!" << endl;
    }
    Sleep(3000);
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
    int damage = (damageCalculator(power, atk, def) * damageMultiplier(attacker, defender, move));
    damage = (int)damage;
    lowerHealth(defender, damage);
    Sleep(3000);
    system("CLS");
}



void lowerHealth(Pokemon& defender, int damage) { // Ends the game if a pokemon falls below 0 hp
    if (defender.hp - damage < 0) { // Sets up end of battle
        defender.hp = 0;
    }
    else
        defender.hp -= damage;
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
    system("CLS");
    displayHealth(pPokemon, tempPlayerPokemon, cPokemon, tempCpuPokemon);
    cout << string(15, '\n');
    while(true) {
        displayOptions();
        if (selectOption() == 0) {
            system("CLS");
            displayHealth(pPokemon, tempPlayerPokemon, cPokemon, tempCpuPokemon);
            displayAttacks(tempPlayerPokemon);
            int option = selectOption();
            if (option != 4) {
                determineMove(tempPlayerPokemon, tempCpuPokemon, option);
                break;
            }
            else if(option == 4)
                continue;
        }
        else if (selectOption() == 1) {
            system("CLS");
            displayHealth(pPokemon, tempPlayerPokemon, cPokemon, tempCpuPokemon);
            getStats(tempPlayerPokemon);
        }
        break;
    }
    if (isFainted(tempPlayerPokemon, tempCpuPokemon)) {
        endBattle(tempPlayerPokemon, tempCpuPokemon);
    }
    else
        cpuTurn();
}



random_device r;
uniform_int_distribution<int> random(0, 3); // Opponent uses a random ability
void cpuTurn() { // Computer's turn to attack
    system("CLS");
    displayHealth(pPokemon, tempPlayerPokemon, cPokemon, tempCpuPokemon);
    cout << string(15, '\n');
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
    if (isFainted(tempPlayerPokemon, tempCpuPokemon)) {
        endBattle(tempPlayerPokemon, tempCpuPokemon);
    }
    else
        playerTurn();
}


bool isFainted(Pokemon& player, Pokemon& opponent) {
    if (player.hp == 0 || opponent.hp == 0)
        return true;
    return false;
}



void endBattle(Pokemon& player, Pokemon& opponent) {
    if (player.hp == 0) {
        cout << player.name << " fainted!\nYou lost!" << endl;
    }
    else
        cout << opponent.name << " fainted!\nYou won!" << endl;
}