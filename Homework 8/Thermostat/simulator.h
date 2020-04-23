/* simulator.h
   Jay-Mark Pascua
   CS 201
   04/22/2020
   Starts simulation loop
*/

#pragma once
#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "agent.h"
#include "environment.h"

class Simulator {

public:

	bool runSim = true;
	int iterationCounter = 1;

	Environment room;
	Agent thermostat;

	Simulator() {
		room;
		thermostat;
	}

	void run(); // Runs the simulator loop

	void askOwner(); // Asks if user wants to set desired temp every 10 iterations; Returns user's option

};


#endif // !SIMULATOR_H
