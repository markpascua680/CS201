/* environment.cpp
   Jay-Mark Pascua
   CS 201
   04/22/2020
   Simulates environment
*/

#include <iostream>
#include "environment.h"

int Environment::iteration() { // Changes temp by 1 or -1 if heater is on or off
    if (_heater) // Increase temp is heater is on
        return _temp++;
    return _temp--; // Decrease if off
}

int Environment::getTemp() { // Returns the current temp
    return _temp;
}

bool Environment::toggleHeater(bool toggle) { // Turns heater on/off
    return _heater = toggle;
}

std::string Environment::getHeaterState() { // Returns 1/0 if heater is on/off
    if (_heater)
        return "Heater is on";
    return "Heater is off";
}