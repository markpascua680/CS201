#pragma once
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "agent.h"

class Environment {

public:
	Environment() {
		_temp = 65;
		_heater = false;
	}

	int iteration(); // Changes temp by 1 or -1 if heater is on or off

	int getTemp(); // Returns the current temp

	bool toggleHeater(bool toggle); // Turns heater on/off

	bool getHeaterState(); // Returns 1/0 if heater is on/off

private:
	int _temp; // Temperature
	bool _heater; // True if heater is on
};



#endif 
