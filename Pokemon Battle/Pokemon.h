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
#include <tuple>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>

using namespace std;


struct Pokemon
{
    string name;
    string type;
    double hp;
    double atk;
    double def;
    double spAtk;
    double spDef;
    double speed;
};

Pokemon pSelect(int id);

#endif
