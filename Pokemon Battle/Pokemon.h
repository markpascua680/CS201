/* Pokemon.h
   Jay-Mark Pascua
   CS 201
   03/22/2020
   Links files together
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <random>
#include <math.h>
#include <cmath>
#include <Windows.h>

using namespace std;

class Attacks {
public:
    int pp;
    Attacks(
        string name,        // Name of attack
        string type,        // Grass, Fire, Water, etc.
        string category,    // Physical, Special, Status effect, etc.
        int power,       // Base damage of the attack
        int accuracy,    // Chance of hitting attack
        int pp1              // Power Points; how many times it can be used in battle
    ) {
        _name = name;
        _type = type;
        _category = category;
        _power = power;
        _accuracy = accuracy;
        _pp, pp = pp1;
      }
    int getPower() {
        return _power;
    }
    string getName() {
        return _name;
    }
    string getType() {
        return _type;
    }
    string getCategory() {
        return _category;
    }

private:
    string _name;
    string _type;
    string _category;
    int _power;
    int _accuracy;
    int _pp;

};

struct Pokemon
{
    string name;
    string type;
    vector<Attacks> attack;
    int level;
    int hp;
    int atk;
    int def;
    int spAtk;
    int spDef;
    int speed;
    int accuracy;
};

// Functions
Pokemon pSelect(int id); // Randomly selects opponent's pokemon
vector<Attacks> makeMoveSet(int id); // Creates movesets for the pokemon
Pokemon choosePoke(); // Player chooses a pokemon
void decideTurn(Pokemon& pPokemon, Pokemon& cPokemon); // Decides who goes first based on pokemon's speed
void displayOptions(); // Displays player's options during turn
void displayAttacks(Pokemon& pPokemon); // Displays player's pokemon attacks
int selectOption(); // Returns the number of the key pressed by player

#endif
