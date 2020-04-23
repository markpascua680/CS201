/* environment.cpp
   Jay-Mark Pascua
   CS 201
   04/22/2020
   Simulates environment
*/

#include <iostream>
#include "environment.h"

int Environment::iteration() {
    if (_heater)
        return _temp++;
    return _temp--;
}

int Environment::getTemp() {
    return _temp;
}

bool Environment::getHeaterState() {
    return _heater;
}