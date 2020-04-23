/* thermostat.cpp
   Jay-Mark Pascua
   CS 201
   04/22/2020
   Simulates a thermostat in response to the environment
*/

#include <iostream>
#include "environment.h"
#include "agent.h"

int main() {
    Environment room;
    Agent thermostat;

    std::cout << "CURRENT TEMP IS: " << thermostat.perceive(room) << std::endl;
    std::cout << "Heater is on: " << room.getHeaterState() << std::endl;
    thermostat.think(room);


    return 0;
}