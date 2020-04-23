/* thermostat.cpp
   Jay-Mark Pascua
   CS 201
   04/22/2020
   Simulates a thermostat in response to the environment
*/

#include <iostream>
#include "environment.h"

int main() {
    Environment room;

    std::cout << "CURRENT TEMP IS: " << room.getTemp() << std::endl;
    std::cout << "Heater is on: " << room.getHeaterState() << std::endl;

    return 0;
}