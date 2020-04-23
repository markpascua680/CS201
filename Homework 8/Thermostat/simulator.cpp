/* simulator.cpp
   Jay-Mark Pascua
   CS 201
   04/22/2020
   Starts simulation loop
*/
#include <iostream>
#include "simulator.h"

void Simulator::run() { // Runs the simulator loop
    while (runSim) { // Loops until stopped by user input
        room.iteration();
        thermostat.perceive(room);
        thermostat.think(room);
        thermostat.act(room);
        askOwner();
    }
}

void Simulator::askOwner() { // Asks if user wants to set desired temp every 10 iterations
    std::cout << "Select an option (enter its number):" << std::endl; 
    std::cout << "[1] Set Temperature Range\n";
    std::cout << "[2] Quit Simulation\n";

    int opt; // User's option
    std::cin >> opt;

    while(opt != 1 && opt != 2) { // User input loop
        std::cout << "Invalid option\n";
        std::cin >> opt;
    }
}