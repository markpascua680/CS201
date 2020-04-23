#pragma once
#ifndef AGENT_H
#define AGENT_H

#include "environment.h"

class Agent {

public:

	int desiredTempLow = 0;
	int desiredTempHigh = 0;

	Agent() {

	}

	int perceive(class Environment& room); // Ask Environment for current temperature

	void think(class Environment& room); // Determine the action that the agent should take

	void act(class Environment& room); // Tells Environment to turn heater on/off

};


#endif // !AGENT_H
