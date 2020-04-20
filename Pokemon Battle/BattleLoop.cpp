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
double damageCalculator(Pokemon& attacker, double p, double a, double d);
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
    printBoxTop();
    cout << endl;
    cout << char(186) << ' ' << setw(10) << left << "ATK: " << setw(24) << pokemon.atk << char(186) << endl;
    cout << char(186) << ' ' << setw(10) << left << "DEF: " << setw(24) << pokemon.def << char(186) << endl;
    cout << char(186) << ' ' << setw(10) << left << "SP.ATK: " << setw(24) << pokemon.spAtk << char(186) << endl;
    cout << char(186) << ' ' << setw(10) << left << "SP.DEF: " << setw(24) << pokemon.spDef << char(186) << endl;
    cout << char(186) << ' ' << setw(10) << left << "ACC: " << setw(24) << pokemon.accuracy << char(186) << endl;
    printBoxBottom();
    system("PAUSE");
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
        clearScreen(pPokemon, tempPlayerPokemon, cPokemon, tempCpuPokemon);
        cout << string(15, '\n');
        Sleep(1500);
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
    clearScreen(pPokemon, tempPlayerPokemon, cPokemon, tempCpuPokemon);
    cout << string(15, '\n');
    string status = attacker.attack[move].getName();
    attacker.attack[move].pp -= 1;
    printBoxTop();
    cout << '\n' << char(186) << ' ' << attacker.name << " used " << attacker.attack[move].getName() << '!' << endl;

    if (status == "Growth") { // Raises user's attack and special attack by 10%
        attacker.atk += attacker.atk * 0.1;
        attacker.spAtk += attacker.spAtk * 0.1;
        cout << char(186) << ' ' << "Its attack/special attack rose!" << endl;
    }
    else if (status == "Defense Curl") { // Raises user's defense by 10%
        attacker.def += attacker.def * 0.1;
        cout << char(186) << ' ' << "Its defense rose!" << endl;
    }
    else if (status == "Smokescreen") { // Lowers target's accuracy by 10%
        defender.accuracy -= defender.accuracy * 0.1;
        cout << char(186) << ' ' << defender.name << "'s accuracy fell!" << endl;
    }
    else if (status == "Tail Whip") { // Lowers target's defense by 10%
        defender.def -= defender.def * 0.1;
        cout << char(186) << ' ' << defender.name << "'s defense fell!" << endl;
    }
    else if (status == "Play Nice") { // Lowers target's attack by 10%
        defender.atk -= defender.atk * 0.1;
        cout << char(186) << ' ' << defender.name << "'s attack fell!" << endl;
    }
    playSound(attacker, move);
    Sleep(3000);
}



void offensiveMove(Pokemon& attacker, Pokemon& defender, int move) {
    clearScreen(pPokemon, tempPlayerPokemon, cPokemon, tempCpuPokemon);
    cout << string(15, '\n');
    double power = attacker.attack[move].getPower();
    double atk;
    double def;
    if (attacker.attack[move].getCategory() == "Physical") { // If attack is physical, use attacker's atk stat and defender's def stat
        atk = attacker.atk;
        def = defender.def;
    }
    else {
        atk = attacker.spAtk;
        def = defender.spDef;
    }
    attacker.attack[move].pp -= 1;
    printBoxTop();
    cout << '\n' << char(186) << ' ' << attacker.name << " used " << attacker.attack[move].getName() << '!' << endl;
    playSound(attacker, move);
    double damage = (damageCalculator(attacker, power, atk, def) * damageMultiplier(attacker, defender, move));
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
            cout << char(186) << ' ' << "It's super effective!" << endl;
            return 2;
        }
        else if (defenderType == "Grass" || defenderType == "Fire") { 
            cout << char(186) << ' ' << "It's not very effective..." << endl;
            return 0.5;
        }
        else
            return 1;
    }
    else if (attackType == "Fire") { // Fire attacks against other types
        if (defenderType == "Grass") {
            cout << char(186) << ' ' << "It's super effective!" << endl;
            return 2;
        }
        else if (defenderType == "Fire") {
            cout << char(186) << ' ' << "It's not very effective..." << endl;
            return 0.5;
        }
        else
            return 1;
    }
    else if (attackType == "Water") { // Water attacks against other types
        if (defenderType == "Fire") {
            cout << char(186) << ' ' << "It's super effective!" << endl;
            return 2;
        }
        else if (defenderType == "Water" || defenderType == "Grass") {
            cout << char(186) << ' ' << "It's not very effective..." << endl;
            return 0.5;
        }
        else
            return 1;
    }
    else if (attackType == "Electric") {
        if (defenderType == "Water") {
            cout << char(186) << ' ' << "It's super effective!" << endl;
            return 2;
        }
        else if (defenderType == "Electric" || defenderType == "Grass") {
            cout << char(186) << ' ' << "It's not very effective..." << endl;
            return 0.5;
        }
        else
            return 1;
    }
    else if (attackType == "Rock") {
        if (defenderType == "Fire") {
            cout << char(186) << ' ' << "It's super effective!" << endl;
            return 2;
        }
        else
            return 1;
    }
}



double damageCalculator(Pokemon& attacker, double p, double a, double d) // Calculates damage of attacks
{
    double damage = 2 * attacker.level;  
    damage /= 5;
    damage += 2;                         // d = Defender's defense/special defense stat
    damage *= (a / d);                   // a = Attacker's attack/special attack stat
    damage *= p;                         // p = The attack's base power
    damage /= 50;          
    damage += 2;
    damage = round(damage);
    return damage;
}



void playerTurn() { // User can attack or check stats of their own pokemon
    clearScreen(pPokemon, tempPlayerPokemon, cPokemon, tempCpuPokemon);
    
    while(true) {
        cout << string(15, '\n');
        displayOptions();
        if (selectOption() == 0) {
            clearScreen(pPokemon, tempPlayerPokemon, cPokemon, tempCpuPokemon);
            displayAttacks(tempPlayerPokemon);
            int option = selectOption();
            if (option != 4) {
                determineMove(tempPlayerPokemon, tempCpuPokemon, option);
                clearScreen(pPokemon, tempPlayerPokemon, cPokemon, tempCpuPokemon);
                break;
            }
            else if(option == 4)
                system("CLS");
                displayHealth(pPokemon, tempPlayerPokemon, cPokemon, tempCpuPokemon);
                continue;
        }
        else if (selectOption() == 1) {
            clearScreen(pPokemon, tempPlayerPokemon, cPokemon, tempCpuPokemon);
            getStats(tempPlayerPokemon);
            playerTurn();
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
    clearScreen(pPokemon, tempPlayerPokemon, cPokemon, tempCpuPokemon);
    cout << string(15, '\n');

    cout << "Opponent's "; 
    determineMove(tempCpuPokemon, tempPlayerPokemon, random(r));     // What kind of move is used is determined and then passed to 

    if (isFainted(tempPlayerPokemon, tempCpuPokemon)) {              // defensiveMove or offensiveMove functions
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
    clearScreen(pPokemon, tempPlayerPokemon, cPokemon, tempCpuPokemon);
    cout << string(15, '\n');
    printBoxTop();
    cout << endl;
    if (player.hp == 0) {
        cout << char(186) << ' ' << player.name << " fainted!\n" << char(186) << " You lost!" << endl;
    }
    else {
        cout << char(186) << ' ' << opponent.name << " fainted!\n" << char(186) << " You won!" << endl;
    }
    printBoxBottom();
    cout << endl;
    system("PAUSE");
}