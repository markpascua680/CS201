/* agent.cpp
   Jay-Mark Pascua
   CS 201
   04/22/2020
   Process percepts from environment and decides what actions to take to change environment
*/

#include <iostream>
#include "agent.h"

int Agent::perceive(class Environment& room) { // Ask Environment for current temperature
    return room.getTemp();
}

void Agent::think(class Environment& room) { // Determine the action that the agent should take
    act(room);
}

void Agent::act(class Environment& room) { // Tells Environment to turn heater on/off
    if (room.getTemp() < 61)      // Turns heater on if temp is too low
        room.toggleHeater(true);
    else if (room.getTemp() > 72) // Turns heater off if temp is too high
        room.toggleHeater(false);
}