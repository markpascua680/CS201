/* agent.h
   Jay-Mark Pascua
   CS 201
   04/22/2020
   Process percepts from environment and decides what actions to take to change environment
*/

#pragma once
#ifndef AGENT_H
#define AGENT_H

#include "environment.h"

class Agent {

public:

	int desiredTempLow = 60;
	int desiredTempHigh = 75;

	Agent() {
		
	}

	int perceive(class Environment& room); // Ask Environment for current temperature

	void think(class Environment& room); // Determine the action that the agent should take

	void act(class Environment& room); // Tells Environment to turn heater on/off

};


#endif // !AGENT_H
