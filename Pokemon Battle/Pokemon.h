/* Pokemon.h
   Jay-Mark Pascua
   CS 201
   03/22/2020
   Links files together
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;


struct Stats
{
    double hp;
    double atk;
    double def;
    double spAtk;
    double spDef;
    double speed;
};

struct Pokemon
{
    Stats Bulbasaur;
    Stats Charmander;
    Stats Squirtle;
    Stats Pikachu;
    Stats Bidoof;
};

string pSelect(int id);
#endif
