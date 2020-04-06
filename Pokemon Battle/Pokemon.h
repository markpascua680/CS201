/* Pokemon.h
   Jay-Mark Pascua
   CS 201
   03/22/2020
   Links files together
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>

using namespace std;

class Attacks {
public:
    Attacks(
        string name,        // Name of attack
        string type,        // Grass, Fire, Water, etc.
        string category,    // Physical, Special, Status effect, etc.
        double power,       // Base damage of the attack
        int accuracy,       // Chance of hitting attack
        int pp              // Power Points; how many times it can be used in battle
    ) {
        _name = name;
        _type = type;
        _category = category;
        _power = power;
        _accuracy = accuracy;
        _pp = pp;
      }

    int getPower() {
        return _power;
    }

private:
    string _name;
    string _type;
    string _category;
    double _power;
    int _accuracy;
    int _pp;

};

struct Pokemon
{
    string name;
    string type;
    vector<Attacks> attack;
    int level;
    double hp;
    double atk;
    double def;
    double spAtk;
    double spDef;
    double speed;
};

Pokemon pSelect(int id);

vector<Attacks> makeMoveSet(int id);

#endif
