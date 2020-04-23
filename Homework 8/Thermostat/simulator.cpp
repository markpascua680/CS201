/* simulator.cpp
   Jay-Mark Pascua
   CS 201
   04/22/2020
   Starts simulation loop
*/
#include <iostream>
#include <sstream>
#include <limits>
#include "simulator.h"

void Simulator::run() { // Runs the simulator loop
    while (runSim) { // Loops until stopped by user input
        std::cout << "Min. Temp: " << thermostat.desiredTempLow << char(248) << 'F'
            << "\tMax. Temp: " << thermostat.desiredTempHigh << char(248) << 'F' << std::endl;
        room.iteration();

        std::cout << "The current temperature is: ";
        std::cout << thermostat.perceive(room) << std::endl;

        thermostat.think(room);

        thermostat.act(room);

        std::cout << room.getHeaterState() << std::endl;

        if (iterationCounter % 10 == 0) { // Asks for user input every 10 iterations
            askOwner();
        }

        iterationCounter++;

        std::cout << std::endl;
    }
}

void Simulator::askOwner() { // Asks if user wants to set desired temp every 10 iterations
    std::cout << "\nSelect an option (enter its number):" << std::endl; 
    std::cout << "[1] Set Temperature Range\n";
    std::cout << "[2] Quit Simulation\n";


    char opt; // User's option
    std::cin >> opt;

    std::istringstream iss(opt);
    int num;
    iss >> num; // Reads only int from input


    while(opt != '1' && opt != '2' && !iss) { // Ensures input is valid
        std::cout << "Invalid option\n";
        std::cin >> opt;
        iss >> num;
    }


    int minTemp;
    int maxTemp;
    if (opt == '1') { // Changes the desired temp range

        std::cout << "Enter desired minimum temperature: "; // User inputs min temp
        std::cin >> minTemp;

        while (!std::cin) { // Ensures input is a number
            std::cout << "\nPlease enter a desired minimum temperature: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> minTemp;
            
        }

        std::cout << "Enter desired maximum temperature: "; // User inputs max temp
        std::cin >> maxTemp;

        while (!std::cin || maxTemp < minTemp) { // Ensures input is a number
            if (maxTemp < minTemp) {
                std::cout << "\nMaximum temperature cannot be greater than minimum temperature." << std::endl;
            }
            std::cout << "\nPlease enter a desired maximum temperature: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> maxTemp;
        }
        thermostat.desiredTempLow = minTemp;
        thermostat.desiredTempHigh = maxTemp;
    }


    else if (opt == '2') { // Stop simulator
        runSim = false;
        std::cout << "\nHave a good day!" << std::endl;
    }
}